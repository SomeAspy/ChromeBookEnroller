#include <Keyboard.h>
#include "config.cpp"
#include "keys.cpp"

void setup()
{
    Keyboard.begin();
}

void loop()
{
    // SECTION - Show version info
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.write('v');
    Keyboard.releaseAll();

    // SECTION - Tell Chromebook to enter the enrollment dialog after wifi
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('e');
    Keyboard.releaseAll();

    // SECTION - Open quick settings menu
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('s');
    Keyboard.releaseAll();

    // SECTION - Navigate quick WiFi menu
    Keyboard.write(KEY_TAB);
    Keyboard.write(KEY_ENTER);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write(KEY_TAB);
    Keyboard.releaseAll();
    Keyboard.write(KEY_ENTER);

    // SECTION - Join WiFi network
    Keyboard.print(SSID);
    Keyboard.write(KEY_TAB);
    Keyboard.write(KEY_DOWN_ARROW);
    Keyboard.write(KEY_DOWN_ARROW);
    Keyboard.write(KEY_TAB);
    Keyboard.print(wifi_password);
    Keyboard.write(KEY_ENTER);
    // Wait for WiFi to finish connecting (in ms)
    delay(4000);

    // SECTION - Navigate setup slides
    Keyboard.write(KEY_ENTER);
    Keyboard.write(KEY_ENTER);

    // SECTION - Enrollment
    Keyboard.print(enroller_username);
    // Wait for Google to check the email (in ms)
    delay(2000);
    Keyboard.print(enroller_password);
    Keyboard.write(KEY_ENTER);
    // Wait for login (in ms)
    delay(15000);

    // SECTION - Asset page
    Keyboard.write(KEY_TAB);
    Keyboard.write(KEY_TAB);
    Keyboard.write(KEY_ENTER);

    // SECTION - Completion
    Keyboard.write(KEY_ENTER);

    while (true)
    {
        // Don't repeat the process
    }
}