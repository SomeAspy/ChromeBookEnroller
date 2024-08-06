#include <Keyboard.h>
#include "config.cpp"
#include "keys.cpp"

// NOTE - Main script is in setup() because we only want it to run once, and then loop is just run after indefinitely.
void setup()
{
    Keyboard.begin();
    delay(3000); // Wait for keyboard initialization

    // SECTION - Show version info
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.write('v');
    Keyboard.releaseAll();
    delay(100);

    // SECTION - Tell Chromebook to enter the enrollment dialog after wifi
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('e');
    Keyboard.releaseAll();
    delay(100);

    // SECTION - Open quick settings menu
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('s');
    Keyboard.releaseAll();
    delay(100);

    // SECTION - Navigate quick WiFi menu
    Keyboard.write(KEY_TAB);
    Keyboard.write(KEY_ENTER);
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(100);
    Keyboard.write(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    Keyboard.write(KEY_ENTER);
    delay(500);

    // SECTION - Join WiFi network
    Keyboard.print(SSID);
    Keyboard.write(KEY_TAB);
    Keyboard.write(KEY_DOWN_ARROW);
    Keyboard.write(KEY_DOWN_ARROW);
    Keyboard.write(KEY_TAB);
    Keyboard.print(wifi_password);
    Keyboard.write(KEY_ENTER);
    delay(17000); // Wait for WiFi to finish connecting

    // SECTION - Navigate setup slides
    Keyboard.write(KEY_ENTER);
    delay(500); // Loading WiFi slide takes a moment
    Keyboard.write(KEY_ENTER);
    delay(6500); // Wait for enterprise enrollment to display

    // SECTION - Enrollment
    Keyboard.print(enroller_username);
    Keyboard.write(KEY_ENTER);
    delay(2000); // Wait for Google to check the email
    Keyboard.print(enroller_password);
    Keyboard.write(KEY_ENTER);
}

void loop()
{
    // Wig-wag lights to indicate script finished
    RXLED0;
    TXLED1;
    delay(500);
    RXLED1;
    TXLED0;
    delay(500);
}
