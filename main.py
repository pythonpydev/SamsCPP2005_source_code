""".git/main.py
Analyse chapter of cpp text book
Identify code listings
Extract code listing from:
http://101.lv/learn/C++/htm/fm.htm
http://101.lv/learn/C++/index.htm
Save as .cpp file
"""

import os
import os.path
import string
import re


def find_whitespace(st):
    for index, character in enumerate(st):
       if character.isspace():
            return index


def read_file(path):
    # Using readline()
    new_script = "" 
    scripts = []
    is_script = False
    
    with open(path) as fp:
        while True:
            #count += 1
            line = fp.readline()

            # check for the word Listing+" "+int+"."int"+"."+" "
            # e.g. Listing 5.1.
            result = re.search("^Listing\s\d\d?[.]\d[.]\s", line) 

            if result:
                # if found match for "Listing..."
                new_script += f"// {line}" + "\n"

                while True:
                    # get code extract
                    line = fp.readline()

                    if re.search(r"Listing\s\d\d?.", line):
                        continue      

                    if re.search("^Output:", line):
                        # found end of script
                        is_script = False
                        new_script += "// end of script...\n"
                        scripts.append(new_script)
                        new_script = "" # reset script
                        break              

                    if line.isspace() and is_script:
                        # found end of script
                        is_script = False
                        new_script += "// end of script...\n"
                        scripts.append(new_script)
                        new_script = "" # reset script
                        break
                    elif line.isspace() and not is_script:
                        continue

                    # remove characters before first white space
                    space_index = find_whitespace(line)
                    if space_index < 10:
                        is_script = True
                        new_script += line[space_index:] + "\n"
                        continue
                    

    
            if not line:
                break

    return scripts


def save_scripts(scripts, chapter_num, new_file_type):
    for script_count, new_script in enumerate(scripts):
        if int(chapter_num)<10:
            new_file_name = f"ch0{chapter_num}_{chapter_num}.{script_count+1}.txt"
        else:
            new_file_name = f"ch{chapter_num}_{chapter_num}.{script_count+1}.txt"

        folder = f"chapter{chapter_num}"

        if not os.path.isdir(folder):
            #  path / folder doesn't exist
            os.mkdir(folder)

        # write code to new cpp file
        f= open(f"{os.getcwd()}/{folder}/{new_file_name[:-3]}{new_file_type}","w+")
        f.write(new_script)
        f.close()


def main():
    # code starts executing here
    # get path to folder where text files reside 
    file_type = ".txt" # file type we are reading from
    new_script = "" # new code script
    new_file_type = "cpp" # file type we are writing to 
    scripts = [] # list containing all the code scripts from each chapter
    script_count = 0

    print(f"Reading files ...")
        
    for filename in os.listdir(path=os.getcwd()):
        if filename.endswith(file_type):
            full_path = f"{os.getcwd()}/{filename}"
            # read file and remove line numbers 
            scripts = read_file(full_path)
            if filename[8] == ".":
                save_scripts(scripts, filename[7], new_file_type)
            else:
                save_scripts(scripts, filename[7:9], new_file_type)

    print(f"Process completed.")


if __name__ == "__main__":
    main()