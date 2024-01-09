import os
import json
import sys

def find_mp4_files(directory):
    mp4_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".mp4"):
                if "overlay" in file:
                    continue
                full_path = os.path.join(root, file)
                mp4_files.append(full_path)
    return mp4_files

def main():
    if len(sys.argv) != 2:
        print("Usage: python script.py <directory>")
        sys.exit(1)

    directory = sys.argv[1]
    mp4_files = find_mp4_files(directory)

    with open('data/mp4_files_list.json', 'w') as f:
        json.dump(mp4_files, f, indent=4)

    print(f"MP4 files list saved to mp4_files_list.json")

if __name__ == "__main__":
    main()
