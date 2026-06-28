# Download Manager

[Persian](https://github.com/ussefT/DownloadManger/blob/main/README_fa.md)

A simple command-line download manager written in C. It uses `wget` under the hood to download files either from a single URL or from a list of URLs stored in a text file.

## Features

- **Add URL** — create a text file and add URLs to it line by line.
- **Download direct** — download a file from a single URL entered at runtime.
- **Download links** — read URLs from a file and download them one by one.
- Resumable downloads (`wget -c`).

## Requirements

- A C compiler (`gcc` or `clang`)
- `wget` installed and available on your `PATH`

## Install / Compile

```bash
gcc main.c file.c -o downloadManagerd //compile to executaion
```

This produces an executable named `downloadManagerd`.



```bash
chmod +x downloadManager // access to run
```


## Usage

```bash
./downloadManagerd // run app
```

You will see the following menu:

```
---------- Download Manager ----------
1- Add URL
2- Download direct
3- Download links
0- exit
```

- Choose **1** to create/overwrite a file and add URLs to it (type `0` to stop).
- Choose **2** to download from a single URL.
- Choose **3** to download all URLs listed in a file (one URL per line).
- Choose **0** to exit.


## Project Structure

| File      | Description                                  |
|-----------|----------------------------------------------|
| `main.c`  | Menu logic and download handling             |
| `file.c`  | File helper functions (exists, read, write)  |
| `file.h`  | Header declarations for `file.c`             |
