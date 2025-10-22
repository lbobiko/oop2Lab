#include "Dashboard.h"
#include <chrono>
#include <thread>
#include <string>
#include "Car.h"
#include "Constants.h"
#include <iostream>
#include <termios.h>    // konfiguracja trybu terminala (POSIX)
#include <unistd.h>     // STDIN_FILENO i funkcje POSIX (read, write)
#include <fcntl.h>      // ustawienia deskryptorów (np. non-blocking)
#include <cstdlib>      // atexit()

using namespace std;

// Zmienna globalna przechowująca oryginalne ustawienia terminala
// (żeby można je było potem przywrócić)
struct termios orig_termios;

char readKeyNonBlocking() {
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == '\033') { // ESC — możliwa sekwencja strzałek
            char seq[2];
            if (read(STDIN_FILENO, &seq[0], 1) == 1 && read(STDIN_FILENO, &seq[1], 1) == 1) {
                if (seq[0] == '[') {
                    if (seq[1] == 'A') return 'W'; // ↑
                    if (seq[1] == 'B') return 'S'; // ↓
                    if (seq[1] == 'C') return 'R'; // → na przyszłość
                    if (seq[1] == 'D') return 'L'; // ← na przyszłość
                }
            }
            return '\0'; // nieznana sekwencja ESC — ignore
        }
        return c; // zwykły znak (np. 'w', 's', ' ', 'e', 'q')
    }
    return '\0'; // nic nie wciśnięto
}

void disableRawMode() {
    // Przywraca oryginalne ustawienia terminala
    // TCSAFLUSH = odczeka aż wszystko z bufora wyjścia się zapisze, a potem zastosuje zmianę
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    // Pobiera aktualną konfigurację terminala (czyli normalny tryb)
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode); // automatycznie przywróci ustawienia po zakończeniu programu

    struct termios raw = orig_termios; // tworzy kopię aktualnych ustawień
    raw.c_lflag &= ~(ECHO | ICANON); // wyłącza echo i tryb kanoniczny
    // - ECHO powoduje, że to co piszemyemy w terminalu jest wyświetlane
    // - ICANON powoduje, że terminal czeka na ENTER zanim wyśle dane
    // Te dwa pola kontrolują sposób oczekiwania na dane:
    // VMIN  = minimalna liczba bajtów potrzebna do zwrócenia z read()
    // VTIME = maksymalny czas oczekiwania (dziesiąte sekundy)
    // Ustawienie ich na 0 powoduje, że read() będzie:
    //  - nieblokujące (natychmiast zwróci 0 jeśli nic nie ma),
    //  - idealne do pętli symulacji w czasie rzeczywistym.
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 0;
    // Zastosuj nowe ustawienia do standardowego wejścia (stdin)
    // TCSAFLUSH: opróżnia bufor przed zmianą, żeby uniknąć śmieci
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // kod ANSI: czyści i ustawia kursor w lewym górnym rogu
};

int main() {
    enableRawMode();
    bool running = true;
    Car car("Toyota", "Green", 0);
    Dashboard dash;
    clearScreen();
    car.setThrottle(1.0);
    dash.render(car);
    double brakeHoldTimer = 0.0; // hamulec aktywny, jeśli > 0

    while (running) {
        char key = readKeyNonBlocking();

        switch (key) {
            case 'W': // ↑ — gaz WŁĄCZONY
                car.setThrottle(1.0);
                break;
            case 'S': // ↓ — gaz WYŁĄCZONY
                car.setThrottle(0.0);
                break;
            case ' ': // SPACE — hamulec tylko podczas trzymania (auto‑repeat)
                brakeHoldTimer = BRAKE_HOLD_SEC;
                break;
            /*case 'e': case 'E': // włącz/wyłącz silnik (toggle)
                car.setEngine(!car.getEngine());
                break;*/
            case 'q': // wyjście z programu
                running = false;
                break;
        }

        // Hamulec tylko podczas trzymania: licznik maleje co tick
        if (brakeHoldTimer > 0.0) {
            brakeHoldTimer -= DT;
            if (brakeHoldTimer < 0.0) brakeHoldTimer = 0.0;
        }
        car.setBrake(brakeHoldTimer > 0.0);

        car.update(DT);
        clearScreen();
        dash.render(car);
        std::this_thread::sleep_for(std::chrono::duration<double>(DT));
    }

    disableRawMode();

    return 0;
}