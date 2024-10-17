
# Arduino Door Display with Sensor Integration

This project was created for fun during the second semester of my junior year at the University of North Carolina at Chapel Hill. I wanted to create a cool, interactive, and technical display for my bedroom, blending hardware and software to serve as the ultimate piece of decor. This project utilizes an Arduino Uno, a DHT11 sensor, an IR receiver, and an LCD display to showcase personalized messages, environmental data, and enable remote-controlled interaction.

## Features
- **Custom Messages:** Displays rotating, personalized messages on a 16x2 LCD screen.
- **Environmental Monitoring:** Live temperature (Fahrenheit) and humidity readings are displayed using the DHT11 sensor.
- **IR Remote Control:** Navigate through different screens using an infrared remote.
- **Loading Animation:** A staggered "loading" animation adds a polished touch to the user experience.
- **Iteration Counter:** Keeps track of the number of interaction cycles.

## Components
- **Arduino Uno**: Microcontroller driving the system.
- **16x2 Liquid Crystal Display (LCD)**: For displaying messages and sensor readings.
- **DHT11 Sensor**: Measures temperature and humidity.
- **IR Receiver**: Detects commands from a standard IR remote control (not shown in the image, but functional in the setup).
- **Push Button**: Allows for manual interaction with the display.

## Project Motivation

I wanted to blend hardware with software to create a fun, technical project for my room. I designed this during my junior year at UNC Chapel Hill to make my living space feel more interactive and personalized, showcasing both environmental data and remote-controlled messages. This project reflects my skills in hardware integration and real-time data handling.

## Code Overview

The project relies on several Arduino libraries:
- **LiquidCrystal**: For LCD communication.
- **DHT**: For temperature and humidity sensing.
- **IRremote**: For remote control interaction.

### Key Code Snippet:
```cpp
int temp = dht.readTemperature();
temp = int(temp * 1.8 + 32);
float humidity = dht.readHumidity();
matrix[1][0] = "Temperature: " + String(temp) + "F";
matrix[1][1] = "Humidity: " + String(humidity) + "%";
```

### Circuit Image
![Arduino Display Setup](image.png)

## How to Use

1. **Set up the circuit** as shown in the image above.
2. **Upload the code** to your Arduino.
3. Use the **IR remote** to navigate through messages and data:
   - `0-9`: Displays different messages.
   - `ON/OFF`: Starts or stops the automatic cycling of messages.

## If I Had the Parts Again...

If I still had the necessary parts for this project, I would love to expand it by integrating it with the ChatGPT API. This would allow the display to generate dynamic messages based on input from the remote or even voice commands, making it more interactive and adaptive.

## Skills Demonstrated

This project demonstrates my ability to work with hardware, sensors, and microcontrollers while integrating real-time data processing and user interaction. It showcases a mix of embedded systems, creative problem-solving, and technical skills that are relevant for positions in data engineering and machine learning engineering.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
