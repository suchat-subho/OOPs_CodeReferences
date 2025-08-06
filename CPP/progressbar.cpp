/*
 * Program: C++ Console Progress Bar
 * Description: This program demonstrates how to create a simple text-based
 * progress bar in the console using C++. It simulates a task by pausing
 * for a short duration in a loop and updates the progress bar on the same
 * line using the carriage return ('\r') escape character.
 */

#include <iostream> // For std::cout, std::endl
#include <string>   // For std::string
#include <chrono>   // For std::chrono::milliseconds
#include <thread>   // For std::this_thread::sleep_for

// Function to simulate some work
void do_some_work(int duration_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}

int main() {
    int total_steps = 50; // Total steps for the progress bar
    int bar_width = 50;   // Width of the progress bar itself (e.g., 50 characters for the '#' part)

    std::cout << "Starting simulated task..." << std::endl;

    for (int i = 0; i <= total_steps; ++i) {
        // Calculate current progress percentage
        float progress = (float)i / total_steps;
        int num_hashes = static_cast<int>(progress * bar_width);

        // Print the progress bar
        std::cout << "\r["; // Carriage return to move cursor to start of line, then start of bar
        for (int j = 0; j < num_hashes; ++j) {
            std::cout << "#"; // Print filled part
        }
        for (int j = 0; j < bar_width - num_hashes; ++j) {
            std::cout << " "; // Print empty part
        }
        // Print percentage and flush the output buffer
        std::cout << "] " << static_cast<int>(progress * 100.0) << "%";
        std::cout.flush(); // Ensure the output is immediately displayed

        // Simulate work
        do_some_work(50); // Sleep for 50 milliseconds per step
    }

    std::cout << "\nTask completed!" << std::endl; // Newline after the bar is finished

    return 0;
}
