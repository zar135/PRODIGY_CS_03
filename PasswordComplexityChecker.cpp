#include <iostream>
#include <string>

using namespace std;

bool isUpperCase(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isLowerCase(char ch) {
    return ch >= 'a' && ch <= 'z';
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isSpecialCharacter(char ch) {
    return (ch >= ' ' && ch <= '/') || (ch >= ':' && ch <= '@') ||
           (ch >= '[' && ch <= '`') || (ch >= '{' && ch <= '~');
}

string assessPasswordStrength(const string& password) {
    int length = password.length();
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char ch : password) {
        if (isUpperCase(ch)) hasUpper = true;
        if (isLowerCase(ch)) hasLower = true;
        if (isDigit(ch)) hasDigit = true;
        if (isSpecialCharacter(ch)) hasSpecial = true;
    }

    int score = 0;
    if (length >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    string feedback;
    if (score == 5) {
        feedback = "Password strength: Very Strong";
    } else if (score == 4) {
        feedback = "Password strength: Strong";
    } else if (score == 3) {
        feedback = "Password strength: Medium";
    } else if (score == 2) {
        feedback = "Password strength: Weak";
    } else {
        feedback = "Password strength: Very Weak";
    }

    feedback += "\nFeedback:\n";
    if (length < 8) feedback += "- Password should be at least 8 characters long.\n";
    if (!hasUpper) feedback += "- Include at least one uppercase letter.\n";
    if (!hasLower) feedback += "- Include at least one lowercase letter.\n";
    if (!hasDigit) feedback += "- Include at least one number.\n";
    if (!hasSpecial) feedback += "- Include at least one special character.\n";

    return feedback;
}

int main() {
    string password;
    cout << "Enter a password: ";
    cin >> password;

    string feedback = assessPasswordStrength(password);
    cout << feedback << endl;

    return 0;
}
