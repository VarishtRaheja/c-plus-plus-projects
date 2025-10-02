# 🎯 Number Guessing Game (C++20)

A console-based **Number Guessing Game** written in **Modern C++20**.  
This is the first application in my C++ projects series and demonstrates features like **tuples**, **vectors** for statistics, **random number generation** using `<random>`, and now includes a **difficulty system** (Easy, Medium, Hard).  

---

## 📖 Description
The game generates a **random number** within a user-defined range using `std::uniform_int_distribution`.  
The player must guess the number before their allotted **chances** run out.  

### 💡 Features:
- Dynamic number range (configurable).
- Difficulty settings (`Easy`, `Medium`, `Hard`) that:
  - Adjust the number of **chances** given.
  - Change the **penalty** (number of attempts deducted for wrong guesses).
- Statistics tracked using `std::vector`:
  - Attempts history
  - Win/Loss ratio
- Multiple values returned using **`std::tuple`** (e.g., game result + attempts).

---

## 🎚️ Difficulty Levels

| Difficulty | Chances (Relative) | Behavior |
|------------|---------------------|-----------|
| **Easy**   | Generous chances    | Increased chances; smaller range   |
| **Medium** | Balanced chances    | Moderate penalty                   |
| **Hard**   | Very limited chances| Higher penalty                     |

Example logic:  
- Easy → chances + 1 
- Medium → chances - 1  
- Hard → chances - 2  

*(Exact values can be tweaked in code for flexibility).*

---


## 📌 Planned Extensions
- Add **menu system** to allow difficulty & range selection dynamically.  
- Add **statistics summary screen** after multiple games.  
- Enhance random system to give hints (e.g., hot/cold range).  
- Save persistent game stats to a file.  

---


## ✅ Current Status
- [x] Basic random-number guessing  
- [x] User-defined number range  
- [x] Difficulty levels (Easy/Medium/Hard)  
- [?] Statistics visualization  
- [?] Persistence across sessions  

