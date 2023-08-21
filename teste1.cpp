#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// Structure definition for a university course.
struct Course {
    string courseNumber;           // Unique identifier for the course.
    string name;                   // Name or title of the course.
    vector<string> prerequisites;  // List of course numbers that are prerequisites for this course.
};

/**
 * Tokenizes a string based on a given delimiter.
 * @param s The string to tokenize.
 * @param del The delimiter.
 * @return A vector of tokens.
 */
vector<string> tokenize(const string& s, const string& del = " ") {
    vector<string> stringArray;
    int start = 0;
    int end = s.find(del);

    while (end != -1) {
        stringArray.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    stringArray.push_back(s.substr(start, end - start));
    return stringArray;
}

/**
 * Loads course data from a file into an unordered_map.
 * @param courses The unordered_map to store the courses.
 * @return True if loading is successful, otherwise false.
 */
bool LoadDataStructure(unordered_map<string, Course>& courses) {
    cout << "Enter the filename with course data: ";
    string filename;
    cin >> filename;

    ifstream fin(filename, ios::in);
    if (!fin) {
        cout << "Error: File not found or couldn't be opened.\n";
        return false;
    }

    string line;
    while (getline(fin, line)) {
        vector<string> tokens = tokenize(line, ",");

        if (tokens.size() >= 2) {
            Course course;
            course.courseNumber = tokens[0];
            course.name = tokens[1];

            if (tokens.size() == 3) {
                course.prerequisites = tokenize(tokens[2], " ");
            }

            courses[course.courseNumber] = course; // Add the course to the map.
        }
    }
    fin.close();
    return true;
}

/**
 * Prints the details of a single course.
 * @param course The course to print.
 */
void printCourse(const Course& course) {
    cout << course.courseNumber << ", " << course.name << endl;
    if (!course.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (const string& prereq : course.prerequisites) {
            cout << prereq << " ";
        }
        cout << "\n\n";
    }
}

/**
 * Prints a list of all courses.
 * @param courses The unordered_map of courses.
 */
void printCourseList(const unordered_map<string, Course>& courses) {
    cout << "Here is a sample schedule:" << endl;
    for (const auto& pair : courses) {
        printCourse(pair.second);
    }
}

/**
 * Searches for a course by course number and prints its details.
 * @param courses The unordered_map of courses.
 */
void searchCourse(const unordered_map<string, Course>& courses) {
    cout << "What course do you want to know about? ";
    string courseNumber;
    cin >> courseNumber;

    auto it = courses.find(courseNumber);
    if (it != courses.end()) {
        printCourse(it->second);
    }
    else {
        cout << "Course with given course number not found\n";
    }
}

/**
 * Displays the main menu options to the user.
 */
void displayMenu() {
    cout << "\n1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
    cout << "What would you like to do? ";
}

int main(int argc, char** argv) {
    unordered_map<string, Course> courses; // Map to store courses.
    cout << "Welcome to the course planner." << endl;

    int ch;
    do {
        displayMenu();

        // Check for valid input.
        if (!(cin >> ch)) {
            cin.clear(); // Clear the fail state.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input buffer.
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (ch) {
        case 1:
            LoadDataStructure(courses);
            break;
        case 2:
            if (courses.empty()) {
                cout << "Please load the data structure first." << endl;
            }
            else {
                printCourseList(courses);
            }
            break;
        case 3:
            if (courses.empty()) {
                cout << "Please load the data structure first." << endl;
            }
            else {
                searchCourse(courses);
            }
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;
        default:
            cout << ch << " is not a valid option." << endl;
        }
    } while (ch != 9);

    return 0;
}
