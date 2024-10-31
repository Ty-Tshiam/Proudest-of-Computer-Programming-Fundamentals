# Diabetes Data Analysis in C

This project is a C program designed to analyze diabetes statistics across various Canadian provinces, using data from a CSV file. It computes averages, trends, and comparisons of diabetes percentages by year, location, and age group. The program processes the CSV data and outputs insights for different regions: Canada (national), Quebec, Ontario, Alberta, and British Columbia.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Functions](#functions)

## Features
- **Data Preprocessing**: Cleans and processes CSV file data for analysis.
- **Calculations**: Computes average diabetes rates by age group and year, both nationally and provincially.
- **Comparisons**: Finds the highest and lowest average percentages by province and year.
- **Trends Analysis**: Compares diabetes trends to the national average, helping understand regional health trends over time.

## Installation
1. Clone the repository.
    ```bash
    git clone https://github.com/your-username/diabetes-data-analysis.git
    ```
2. Make sure you have GCC or any compatible C compiler installed.
3. Compile the program:
    ```bash
    gcc diabetes_analysis.c -o diabetes_analysis
    ```

## Usage
1. Place the CSV data file `statscan_diabetes.csv` in the same directory as the program.
2. Run the program:
    ```bash
    ./diabetes_analysis
    ```
3. The program will read from the `statscan_diabetes.csv` file, analyze the data, and display the results in the console.

## File Structure
- `diabetes_analysis.c`: Main program file containing all logic for data cleaning, struct definitions, and calculations.
- `statscan_diabetes.csv`: The input data file containing diabetes statistics.

## Functions
- **`fix()`**: Cleans the input CSV file by handling commas within quotes.
- **`average()`**: Calculates the average of a given data array.
- **`averageYears()`**: Computes average percentages by year.
- **`averageAge()`**: Averages data for a specified age range.
- **`highest()` and `lowest()`**: Finds the year with the highest and lowest diabetes percentages.
- **`compare()`**: Used for sorting arrays to find trends.
