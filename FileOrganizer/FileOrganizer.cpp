#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

int main(int argc, const char* argv[])
{

    std::vector<std::string> extensions;
    std::vector<std::string> files;

    std::vector<std::string> images = { 
                                ".jpg", ".jpeg", ".jif", ".png", ".gif",
                                ".webp", ".tiff", ".tif", ".raw", ".bmp", 
                                ".heif", ".heic", ".svg" };

    std::vector<std::string> videos = { 
                                ".webm", ".mpg", ".mp2", ".mpeg", ".mpv", 
                                ".ogg", ".mp4", ".mp4v", ".m4v", ".avi", 
                                ".wmv", ".mov" };

    std::vector<std::string> documents = { 
                                ".doc", ".docx", ".odt", ".csv", ".xls", 
                                ".xlsx", ".pdf", ".txt" };

    std::vector<std::string> archive = { 
                                ".zip", ".rar", ".7z", ".tar", ".tar.gz", 
                                ".tar.bz2", ".tar.xz", ".iso", ".sys", 
                                ".dll", ".drv", ".ocx", ".ax", ".exe", 
                                ".com", ".bat", ".pif", ".msi", ".appinstaller" };

    // Print out all regular files in a directory 'dir'.
    try {
        const auto dir{ argc == 2 ? fs::path{argv[1]} : fs::current_path() };

        std::string userDirectory = "";
        
        std::cout << "What folder would you like to organize?" << std::endl;
        std::cin >> userDirectory;

        fs::current_path(userDirectory);

        std::cout << "\nCurrent dir: " << userDirectory << '\n'
            << std::string(40, '-') << '\n' << std::endl;

        std::cout << "Files in Current Directory:\n"
            << std::string(40, '-') << '\n';

        for (fs::directory_entry const& entry : fs::directory_iterator(userDirectory)) {
            if (entry.is_regular_file()) {
                std::cout << entry.path().filename() << '\n';
                extensions.push_back(entry.path().filename().extension().string());
                files.push_back(entry.path().filename().string());
            }
        }
        std::cout << "\n";

        for (size_t i = 0; i < files.size(); ++i) {
            if (std::find(images.begin(), images.end(), extensions[i]) != images.end()) {
                fs::create_directory("Images");  // Ensures folder exists
                fs::path source = files[i];
                fs::path destination = fs::path("Images") / files[i];  // OS-independent path

                std::cout << "Moving " << source << " -> " << destination << '\n';  // Debug output
                fs::rename(source, destination);
            }

            if (std::find(videos.begin(), videos.end(), extensions[i]) != videos.end()) {
                fs::create_directory("Videos");
                fs::path source = files[i];
                fs::path destination = fs::path("Videos") / files[i];

                std::cout << "Moving " << source << " -> " << destination << '\n';
                fs::rename(source, destination);
            }

            if (std::find(documents.begin(), documents.end(), extensions[i]) != documents.end()) {
                fs::create_directory("Documents");
                fs::path source = files[i];
                fs::path destination = fs::path("Documents") / files[i];

                std::cout << "Moving " << source << " -> " << destination << '\n';
                fs::rename(source, destination);
            }

            if (std::find(archive.begin(), archive.end(), extensions[i]) != archive.end()) {
                fs::create_directory("Archive");
                if (files[i] == "FileOrganizer.exe")
                    continue;
                fs::path source = files[i];
                fs::path destination = fs::path("Archive") / files[i];

                std::cout << "Moving " << source << " -> " << destination << '\n';
                fs::rename(source, destination);
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}