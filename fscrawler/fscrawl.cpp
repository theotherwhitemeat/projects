#include <deque>
#include <fstream>
#include <iostream>
#include <string>

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

int main()
{
    ifstream fin;
    string dir, filepath;
    DIR *current_dir;
    struct dirent *dir_entry;
    struct stat filestat;

    // files and dirs
    deque<string> dirs;
    deque<string> files;

    // seed root dir
    dirs.push_back("/");

    while (dirs.size() > 0)
    {
        string current_dir_str = dirs.front();
        dirs.pop_front();
        current_dir = opendir(current_dir_str.c_str());
        if (current_dir == NULL)
        {
            cout << "Error(" << errno << ") opening " << current_dir_str << endl;
            continue;
        }
        // Skip '.' and '..' entries
        else if ((current_dir_str == "..") or (current_dir_str == "."))
        {
            continue;
        }
        while ((dir_entry = readdir(current_dir)))
        {
            // Skip '.' and '..' entries
            string dirname = dir_entry->d_name;
            if ((dirname == ".") or (dirname == ".."))
            {
                continue;
            }
            string inode_path = current_dir_str + "/" + dir_entry->d_name;

            // If the file is a directory (or is in some way invalid) we'll skip it 
            if (stat(inode_path.c_str(), &filestat) == -1)
            {
                perror("stat");
                continue;
            }
            else if (S_ISDIR(filestat.st_mode))
            {
                dirs.push_back(inode_path);
                cout << "Found a dir: " << inode_path << endl;
            }
            else
            {
                files.push_back(inode_path);
                cout << "Found a file: " << inode_path << endl;
            }
        }
        closedir(current_dir);
    }
    return 0;
}









