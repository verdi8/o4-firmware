#pragma once

/**
 * @brief Abstract interface for Bluetooth modules configurable with AT commands.
 *
 * This interface isolates module-specific configuration operations from the
 * application-facing Bluetooth controller.
 */
class BluetoothATDevice {
public:
    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~BluetoothATDevice() = default;

    /**
     * @brief Updates the advertised Bluetooth device name.
     *
     * @param name The new Bluetooth name.
     * @return true if the module accepted the new name, false otherwise.
     */
    virtual bool setName(const char* name) = 0;

    /**
     * @brief Updates the serial baud rate used by the Bluetooth module.
     *
     * @param baudRate The baud rate to configure.
     * @return true if the module accepted the new baud rate, false otherwise.
     */
    virtual bool setBaudrate(unsigned long baudRate) = 0;

    /**
     * @brief Updates the pairing PIN used by the Bluetooth module.
     *
     * @param pin The new pairing PIN.
     * @return true if the module accepted the new PIN, false otherwise.
     */
    virtual bool setPinCode(const char* pinCode) = 0;
};