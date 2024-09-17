import tkinter as tk
import RPi.GPIO as GPIO

# Setup GPIO pins for the LEDs
GPIO.setmode(GPIO.BCM)
red_led = 17
green_led = 27
blue_led = 22

# Set GPIO pins as output
GPIO.setup(red_led, GPIO.OUT)
GPIO.setup(green_led, GPIO.OUT)
GPIO.setup(blue_led, GPIO.OUT)

# Turn off all LEDs initially
GPIO.output(red_led, GPIO.LOW)
GPIO.output(green_led, GPIO.LOW)
GPIO.output(blue_led, GPIO.LOW)

# Function to turn on selected LED and turn off others
def select_led():
    selected_led = led_choice.get()
    if selected_led == 'red':
        GPIO.output(red_led, GPIO.HIGH)
        GPIO.output(green_led, GPIO.LOW)
        GPIO.output(blue_led, GPIO.LOW)
    elif selected_led == 'green':
        GPIO.output(red_led, GPIO.LOW)
        GPIO.output(green_led, GPIO.HIGH)
        GPIO.output(blue_led, GPIO.LOW)
    elif selected_led == 'blue':
        GPIO.output(red_led, GPIO.LOW)
        GPIO.output(green_led, GPIO.LOW)
        GPIO.output(blue_led, GPIO.HIGH)

# Exit the GUI and clean up GPIO
def exit_gui():
    GPIO.cleanup()
    root.destroy()

# Create the main window
root = tk.Tk()
root.title("LED Controller")

# Variable to store the selected LED
led_choice = tk.StringVar(value="red")

# Create radio buttons for LED selection
tk.Radiobutton(root, text="Red", variable=led_choice, value="red", command=select_led).pack(anchor=tk.W)
tk.Radiobutton(root, text="Green", variable=led_choice, value="green", command=select_led).pack(anchor=tk.W)
tk.Radiobutton(root, text="Blue", variable=led_choice, value="blue", command=select_led).pack(anchor=tk.W)

# Exit button
exit_button = tk.Button(root, text="Exit", command=exit_gui)
exit_button.pack()

# Start the GUI loop
root.mainloop()