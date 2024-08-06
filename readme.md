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

## Editing tips

If you choose to edit the file to suit your needs better, there are some things you should try to stick to for smooth operation.

- The delay for `Keyboard.begin()` is necessary.
- After "steps" you should pause for 100ms using `delay(100)`
- If a shortcut/key combination doesn't seem to register, you may want to insert a `delay(100)` between pressing and releasing the keys.
- Check out the [Arduino keyboard library for more information](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/)

## Recommended boards

Realistically, this should work on just about any Arduino board, knock-off or not.

In development, a knock-off micro (or nano?) board was used. I could not find the exact one online.

I would suggest the [Arduino Nano Every](https://store-usa.arduino.cc/products/arduino-nano-every), specifically because it is Arduino's cheapest offering, and headers are not pre-soldered on. However, theres a good chance your preferred IT supplier offers these as well.

I would also suggest wrapping your boards in a single layer of clear tape, as we had a few boards short out/act erratically due to what I assume was shorting.

## Common Issues

### Failure rate

There are *some* issues that pop up in edge cases, but these edge cases are infrequent in my own testing (and deployment) of several hundred ChromeBooks. If I had to guess the failure rate is around 5% and even then it just drops you into the enrollment page
I want to balance the amount of time vs failure rate of this script.

### Timing issues or unexpected behavior

If you have timing issues, try adjusting the `delay(x)` lines in the script. All timings are in milliseconds. Feel free to open a PR/issue if you consistently hit a timing issue.

- `delay(100)` is usually inserted to process some keystrokes.
- Other `delay(x)` should be commented as to why it is delayed.

Other times, Google significantly changes the setup UI. If you notice this, it is fairly easy to make small edits to the script, as it only accounts for basic setups. (WPA2 WiFi + Enterprise enrollment via login)

### ChromeVOX

If ChromeVOX starts, exit it with `ESC`, and reinsert the Arduino.

#### Credits

Loosely based off [Amplified IT Centipede script](https://www.amplifiedit.com/centipede/) - [View Gist](https://gist.github.com/SomeAspy/f40418b16cd3f2bcd0fe12be94a3a0cf)
