⚡ Powered Tiles – Piezoelectric Energy Harvesting System

A smart flooring solution that converts human footsteps into electrical energy using piezoelectric sensors and displays the generated voltage and step count in real time using Arduino Uno + I2C LCD module.

📌 Project Overview

Powered Tiles is an innovative energy-harvesting system designed to utilize the mechanical energy wasted during walking. When a user steps on the tile, piezoelectric discs generate AC voltage, which is then rectified, regulated, stored in a battery, and monitored via Arduino.

This project supports green energy, smart city concepts, and renewable power harvesting.

🧠 Features

✔ Harvests electrical energy from footsteps
✔ Real-time voltage display
✔ Footstep count detection
✔ Low cost, modular, and scalable design
✔ Ideal for smart walkway installations

🔌 Arduino Code

The code included in this repository:

Reads analog voltage from piezo array

Counts steps based on voltage threshold

Displays live data on LCD

Outputs readings to Serial Monitor

📁 File included:
powered_tiles.ino

📈 Testing Results
Action	Voltage Range
Light Hand Tap	200–300 mV
Heavy Hand Tap	700–900 mV
50kg User Step	1000–1400 mV
80kg User Step	1600–2200 mV

More pressure → More voltage ⚡

🧩 Applications

Railway stations, airports, malls

Stadiums & event entry pathways

Smart street lighting systems

Emergency lighting backup

Human-powered IoT sensors

🚀 Future Scope

IoT data monitoring (Wi-Fi / Bluetooth)

Waterproof outdoor installation

Supercapacitor storage

Floor energy grid integration

Improved mechanical compression system

💡 How to Use

Download the code

Open in Arduino IDE

Select board → Arduino Uno

Connect components as per circuit diagram

Upload code and test by stepping on tile

Created by -Team power tiles
