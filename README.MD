# video checker

`python bin/make_json.py <directory_name>` to generate the json list of mp4s in the directory and subdirectories. it saves to bin/data/mp4_files_list.json

update the ofx config with correct local ofx path (or remake the project with project generator)

`make && make RunRelease` to make and run the program
it will play each video for 5 seconds, then move on to the next one

at the end it will print a list of the videos that couldnt be loaded. 