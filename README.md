<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<p align="center">
  <a href="https://www.uniwa.gr" target="_blank">University of West Attica</a> ·
  <a href="https://ice.uniwa.gr" target="_blank">Department of Computer Engineering and Informatics</a>
</p>

---

<p align="center">
  <strong>Operating Systems II</strong>
</p>

<h1 align="center">
  Process Management with Fork and Wait in C
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<hr/>

<p align="center">
  <strong>Supervision</strong>
</p>

<p align="center">
  Supervisor: Vasileios Mamalis, Professor
</p>
<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/vassilios-mamalis/" target="_blank">UNIWA Profile</a>
</p>

<p align="center">
  Co-supervisor: Nikolaos Psarras, Applications Lecturer<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/nikolaos-psarras/" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/psarras-nikolas-20234183/" target="_blank">LinkedIn</a>
</p>

</hr>

---

<p align="center">
  Athens, April 2022
</p>

---

<p align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSnEvFTdIZ3dMEw24uTHWTb6ZY68tnJa2GtQA&s" width="250"/>
</p>

---

# README

## Process Management with Fork and Wait in C

This repository contains an assignment for **Operating Systems II**, focusing on process creation, management, and synchronization in C using `fork()` and `wait()` system calls.

---

## Table of Contents

| Section | Folder/File                          | Description                                         |
| ------: | ------------------------------------ | --------------------------------------------------- |
|       1 | `assign/`                            | Assignment material for the Fork processes workshop |
|     1.1 | `assign/ASK-1-OS-II-LAB-2021-22.pdf` | Assignment description in English                   |
|     1.2 | `assign/ΕΡΓ-1-ΛΣ-ΙΙ-ΕΡΓ-2021-22.pdf` | Assignment description in Greek                     |
|       2 | `docs/`                              | Documentation covering process creation using fork  |
|     2.1 | `docs/Fork-Processes.txt`            | English documentation for fork processes            |
|     2.2 | `docs/Fork-Διεργασίες.txt`           | Greek documentation for fork processes              |
|       3 | `src/`                               | Source code demonstrating fork usage                |
|     3.1 | `src/exer1a.c`                       | Exercise source code using fork                     |
|     3.2 | `src/fork.c`                         | Basic fork process example                          |
|       4 | `README.md`                          | Project documentation                               |
|       5 | `INSTALL.md`                         | Usage instructions                                  |

---

## 1. Project Overview

The assignment involves developing a C program that:

- Creates a **total of seven processes** following a specific hierarchy.
- Implements **process synchronization** to avoid zombie processes.
- Demonstrates **inter-process communication**.
- Explores scenarios with **orphan and zombie processes**.
- Allows process P2 to spawn **N child processes** dynamically based on user input.

### Key Learning Outcomes

- Understand and apply `fork()` and `wait()` system calls.
- Create and manage process hierarchies.
- Synchronize parent and child processes effectively.
- Handle inter-process communication and message passing.
- Investigate orphan and zombie processes and prevention techniques.

---

## 2. Process Tree Structure

The program creates processes with the following hierarchy:

```bash
			  (P0)
			  /|\
			 / | \
            /  |  \
	       /   |   \
          /    |    \
        (P1)  (P3) (P4)
        /      |
       /       |
      /        |
     /         |
   (P2)       (P5)
```
