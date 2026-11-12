## ⚠️ High-Voltage Safety Warning
This design involves **120V AC mains electricity**, which carries a serious risk of electric shock, fire, or injury. Always disconnect the main power cord before opening the enclosure or servicing wiring, ensure all high-voltage connections are properly insulated inside a non-conductive project box, and maintain physical separation between AC mains wiring and low-voltage Arduino components.

![Project Schematic]
<img width="2480" height="1748" alt="image" src="https://github.com/user-attachments/assets/c25b93eb-9617-4adb-94b7-7b7bd85a34b2" />
# Arduino Esplora Relay-Controlled AC Outlet Box

A custom, Arduino Esplora-controlled AC power enclosure featuring one always-on outlet and one relay-switched outlet. Designed in KiCad.

## Overview
This project uses an **Arduino Esplora** and a **5V Songle Relay Module** (`SRD-05VDC-SL-C`) to safely control a 120V AC wall outlet using low-voltage logic. 

* **Wall Outlet 1 (Always On):** Continuously powered directly from the AC mains distribution blocks. Houses the 5V USB wall adapter that powers the Arduino Esplora.
* **Wall Outlet 2 (Relay Switched):** Routed through the Normally Open (NO) contact of the 5V relay module, allowing the Esplora to toggle connected appliances on and off programmatically.

## Hardware & Bill of Materials (BOM)
* **Microcontroller:** Arduino Esplora
* **Relay Module:** 1-Channel 5V Relay Module (`Songle SRD-05VDC-SL-C`)
* **Cables:** 
  * Mini-USB data/power cable (for Arduino Esplora)
  * 3-Pin TinkerKit-to-DuPont female adapter cable (connecting Esplora `OUT1` to Relay `VCC`, `GND`, and `IN`)
* **AC Components:**
  * Standard 120V AC Duplex Receptacle (with the connecting tabs broken to separate Outlet 1 and Outlet 2)
  * 3-Prong AC Mains Power Cord
  * Lever-nut terminal blocks (Hot, Neutral, and Earth Ground distribution)
  * 5V USB Wall Power Adapter
  * Solid copper wiring

## Wiring & Pinout Summary

### Low-Voltage Control (5V DC)

| Arduino Esplora (TinkerKit OUT1) | Songle Relay Module | Function |
| :--- | :--- | :--- |
| **+5V** | **VCC** | Module power supply |
| **GND** | **GND** | Common ground |
| **Signal (Digital Pin D5)** | **IN / SIG** | Active trigger signal |

### High-Voltage Mains (120V AC)
* **AC Hot:** Split via terminal block to **Wall Outlet 1 (Hot)** and **Relay `COM`**.
* **Switched Hot:** Routed from **Relay `NO` (Normally Open)** to **Wall Outlet 2 (Hot)**.
* **AC Neutral:** Distributed via terminal block to both **Wall Outlet 1** and **Wall Outlet 2**.
* **Earth Ground:** Distributed via terminal block to the ground screws of both outlets.

## Repository Contents
* `*.kicad_pro` / `*.kicad_sch` / `*.kicad_pcb` — Complete KiCad 8/9 project and schematic source files.
* `schematic.png` / `schematic.pdf` — High-resolution schematic export.
* Arduino Esplora Code
