#include <iostream>
#include <fstream>
using namespace std;

// Leap year check
bool isLeapYear(long long year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

int main() {
    long long totalSeconds;
    cout << "Enter time in seconds: ";
    cin >> totalSeconds;

    long long seconds = totalSeconds;

    long long minutes = seconds / 60;
    seconds %= 60;

    long long hours = minutes / 60;
    minutes %= 60;

    long long days = hours / 24;
    hours %= 24;

    long long years = 0;
    while (true) {
        long long daysInYear = isLeapYear(years) ? 366 : 365;
        if (days >= daysInYear) {
            days -= daysInYear;
            years++;
        } else break;
    }

    int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(years)) monthDays[1] = 29;

    int months = 0;
    for (int i = 0; i < 12; i++) {
        if (days >= monthDays[i]) {
            days -= monthDays[i];
            months++;
        } else break;
    }

    // Write CSS
    ofstream css("style.css");
    css << "body{font-family:Arial;background:#1e3c72;color:white;text-align:center;}";
    css << ".card{background:white;color:black;padding:20px;margin:100px auto;width:350px;border-radius:10px;}";
    css.close();

    // Write HTML
    ofstream html("result.html");
    html << "<!DOCTYPE html><html><head>";
    html << "<title>Calendar Time Converter</title>";
    html << "<link rel='stylesheet' href='style.css'>";
    html << "</head><body>";
    html << "<div class='card'>";
    html << "<h2>Calendar-Based Time Breakdown</h2>";
    html << "<p><b>Years:</b> " << years << "</p>";
    html << "<p><b>Months:</b> " << months << "</p>";
    html << "<p><b>Days:</b> " << days << "</p>";
    html << "<p><b>Hours:</b> " << hours << "</p>";
    html << "<p><b>Minutes:</b> " << minutes << "</p>";
    html << "<p><b>Seconds:</b> " << seconds << "</p>";
    html << "</div></body></html>";
    html.close();

    // Open HTML file in browser (Windows)
    system("start result.html");

    cout << "\nResult generated and opened in browser.\n";
    return 0;
}
