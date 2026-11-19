# Campus Lost and Found

A beginner-friendly campus lost-and-found project with a simple HTML/CSS/JavaScript frontend and a C++ console backend.

## Features
- Submit a lost-item or found-item report in the frontend demo.
- Display reported item name, type, and location.
- Add and view item reports in the C++ console program.

## Technologies
- HTML
- CSS
- JavaScript
- C++

## Project structure
```text
Campus-Lost-and-Found/
├── frontend/
│   ├── index.html
│   ├── style.css
│   └── script.js
├── backend/
│   └── main.cpp
└── README.md
```

## Run the frontend
Open `frontend/index.html` in a web browser.

## Run the C++ backend
From the `backend` folder, compile and run:

```bash
g++ main.cpp -o campus_lost_found
./campus_lost_found
```

On Windows with MinGW:

```powershell
g++ main.cpp -o campus_lost_found.exe
.\campus_lost_found.exe
```

## Note
The frontend and C++ console backend are separate demonstration components; they are not connected. The frontend keeps reports only in the current browser page, and the C++ program keeps reports only while it is running.
