#!/bin/bash

# ===========================================
#  C++ Practice Repo Organizer (safe version)
#  Author: Adam Aqil
#  Description: Copies existing .cpp and .h files
#  into structured folders by topic.
# ===========================================

# Create organized folder structure
echo "📁 Creating folder structure..."
mkdir -p 00_basics
mkdir -p 01_intermediate/{Arrays,Structs,Templates,Enums,Pointers}
mkdir -p 02_oop/{Classes,Constructors,Composition,FriendFunctions}
mkdir -p 03_projects
mkdir -p include
mkdir -p misc_experiments

# Function for safe copy (only if file exists)
safe_copy() {
  pattern="$1"
  dest="$2"
  files=( $pattern )
  if [ ${#files[@]} -gt 0 ]; then
    for f in "${files[@]}"; do
      if [ -f "$f" ]; then
        cp -n "$f" "$dest" 2>/dev/null
      fi
    done
  fi
}

echo "🚀 Copying files..."

# === BASICS ===
safe_copy "*Hello*.cpp" "00_basics"
safe_copy "*Loops*.cpp" "00_basics"
safe_copy "*IF*.cpp" "00_basics"
safe_copy "*Char*.cpp" "00_basics"
safe_copy "*Data*.cpp" "00_basics"
safe_copy "*Variable*.cpp" "00_basics"
safe_copy "*cin*.cpp" "00_basics"
safe_copy "*Calc*.cpp" "00_basics"

# === INTERMEDIATE ===
safe_copy "*Array*.cpp" "01_intermediate/Arrays"
safe_copy "*struct*.cpp" "01_intermediate/Structs"
safe_copy "*Struct*.cpp" "01_intermediate/Structs"
safe_copy "*Enum*.cpp" "01_intermediate/Enums"
safe_copy "*template*.cpp" "01_intermediate/Templates"
safe_copy "*Template*.cpp" "01_intermediate/Templates"
safe_copy "*Pointer*.cpp" "01_intermediate/Pointers"
safe_copy "*pointers*.cpp" "01_intermediate/Pointers"

# === OOP ===
safe_copy "*class*.cpp" "02_oop/Classes"
safe_copy "*Class*.cpp" "02_oop/Classes"
safe_copy "*Constructor*.cpp" "02_oop/Constructors"
safe_copy "*Ball*.cpp" "02_oop/Constructors"
safe_copy "*Student*.cpp" "02_oop/Classes"
safe_copy "*Friend*.cpp" "02_oop/FriendFunctions"

# === PROJECTS ===
safe_copy "*Game*.cpp" "03_projects"
safe_copy "*Inventory*.cpp" "03_projects"
safe_copy "*Monster*.cpp" "03_projects"
safe_copy "*Rand*.cpp" "03_projects"
safe_copy "*Hi-lo*.cpp" "03_projects"
safe_copy "*EvenOdd*.cpp" "03_projects"

# === HEADERS ===
safe_copy "*.h" "include"

# === EVERYTHING ELSE ===
safe_copy "*.cpp" "misc_experiments"

# === README + GITIGNORE (if missing) ===
if [ ! -f "README.md" ]; then
  cat <<EOF > README.md
# C++ Practice Repository

This repository contains all my C++ practice files, organized by topic.

## 📁 Folder Structure
- **00_basics/** → Simple syntax, loops, and conditionals
- **01_intermediate/** → Arrays, structs, templates, enums, pointers
- **02_oop/** → Classes, constructors, composition, friend functions
- **03_projects/** → Mini projects and games
- **include/** → Shared header files
- **misc_experiments/** → Random test files or experiments
EOF
  echo "📝 README.md created."
fi

if [ ! -f ".gitignore" ]; then
  cat <<EOF > .gitignore
# Ignore compiled files
*.exe
*.out
*.o
*.obj
*.log
*.tmp
.vscode/
.idea/
build/
EOF
  echo "🧹 .gitignore created."
fi

echo "✅ All done! Files copied into organized folders safely."
echo "   (Original files remain untouched.)"
