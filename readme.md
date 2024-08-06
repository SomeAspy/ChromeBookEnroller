# ChromeBookEnroller

## Tested version: 124.0.6367.95

> [!IMPORTANT]  
> If the folder `ChromeBookEnroller.cpp` is in is *not* named `ChromeBookEnroller` the Arduino IDE will throw an error.

## Setup

1. Copy `config.example.cpp` to `config.cpp`
2. Fill out `config.cpp` according to the information below
3. Upload to Arduino
4. Turn on ChromeBook so the setup page is shown
5. Plug arduino into ChromeBook
6. Wait until lights on Arduino wig-wag
7. Either turn off the device/close the lid **when the device information prompt appears** or enter asset and location information ([If you do this manually, consider using Google Admin Console to do this by serial number](https://arreya.com/kb/assign-asset-id/))

> [!CAUTION]  
> If you close the ChromeBook on the Enterprise Enrollment loading screen, it may not enroll. However, it is safe to do this on the device information screen, it will not prompt again at next boot.

## Config

Example `config.cpp`:

```cpp
#define SSID "chromebook-network"
#define wifi_password "SuperSecretPassword"

#define enroller_username "chromebooks@example.edu"
#define enroller_password "wittyPassword"
```

`SSID`: Network SSID

`wifi_password`: Network password

`enroller_username`: Email of someone in the organization

`enroller_password`: Password for the account

> [!WARNING]  
> Since this will immediately start and emulate a keyboard, you have to let it run through the cycle before uploading new code, You can do this by opening a blank text file.

## Common Failures

### Timing issues or unexpected behavior

If you have timing issues, try adjusting the `delay(x)` lines in the script. Feel free to open a PR/issue if you consistently hit a timing issue.

- `delay(100)` is usually inserted to process some keystrokes.
- Other `delay(x)` should be commented as to why it is delayed.

Other times, Google significantly changes the setup UI. If you notice this, it is fairly easy to make small edits to the script, as it only accounts for basic setups. (WPA2 WiFi + Enterprise enrollment via login)

### ChromeVOX

If ChromeVOX starts, exit it with `ESC`, and reinsert the Arduino.

#### Credits

Loosely based off [Amplified IT Centipede script](https://www.amplifiedit.com/centipede/) - [View Gist](https://gist.github.com/SomeAspy/f40418b16cd3f2bcd0fe12be94a3a0cf)
