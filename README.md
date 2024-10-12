![Alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a5/Flag_of_the_United_Kingdom_%281-2%29.svg/255px-Flag_of_the_United_Kingdom_%281-2%29.svg.png)

# Process Management with Fork and Wait in C

For the requested Assignment, click the link:
[Assignment](Assignment/)

For the Source Code, click the link:
[Code](Code/)

For the detailed Documentation click the link:
[Documentation](Documentation/)

## Course Information
- **Course**: [Operating Systems II](https://ice.uniwa.gr/education/undergraduate/courses/operating-systems-ii/)
- **Semester**: 4
- **Program Study**: [UNIWA](https://www.uniwa.gr/)
- **Department**: [Informatics and Computer Engineering](https://ice.uniwa.gr/)
- **Lab Instructor**: [Psarras Nikolaos](https://ice.uniwa.gr/emd_person/20879/)
- **Academic Season**: 2021-2022

## Student Information
- **Name**: Athanasiou Vasileios Evangelos
- **Student ID**: 19390005
- **Status**: Undergraduate

## Assignment Title
**Title**: Creation and Management of Multiple Processes using Fork and Wait

## Description
This assignment involves developing a C program that uses the `fork()` and `wait()` system calls to create and manage a set of processes with a specific hierarchy (process tree). The program demonstrates inter-process communication, process synchronization, and explores potential scenarios where orphan or zombie processes may be created.

The main objectives are:
- Create a total of **seven processes**, including the main process (P0), following a specific tree structure.
- Ensure that process P0 waits for process P1 to complete before replacing itself with the `cat` command, which prints the source code.
- Implement process synchronization, ensuring that child processes are terminated in a controlled manner using `wait()` to prevent zombie processes.
- Handle messages between processes, where P1 should receive a "hello from your child" message from P3.
- Extend the program so that P2 spawns **N children** based on user input, with each child process printing its PID and PPID before exiting.

### Key Learning Outcomes:
- Understand and implement the `fork()` and `wait()` system calls.
- Manage process creation and ensure proper synchronization between parent and child processes.
- Learn about process hierarchy, inter-process communication, and process termination.
- Investigate and discuss the creation of orphan or zombie processes and how to avoid them.

## Process Tree Structure:
The program follows this process hierarchy:
                (P0)
                / \
               /   \
              /     \
             /       \ 
            /         \
         (P1)        (P2)
          /           /|\
         /           / | \
        /           /  |  \
       /           /   |   \
    (P3)         (P4) (P5) (P6)


## Requirements
- **Operating System**: Linux-based environment (or compatible Unix-like OS).
- **Compiler**: GCC (GNU Compiler Collection).
- **System Calls**: `fork()`, `wait()`, `execv()`, and others as necessary.

## Installation and Usage
### 1. Clone the Repository
Download the repository to your local machine's file system:
```
git clone https://github.com/Operating-Systems-2-aka-Uniwa/Fork.git
```
### 2. Compile the source codes
Compile with gcc compiler the source codes:
```
gcc -o exer1a exer1a.c
```
```
gcc -o fork fork.c
```
### 3. Run the codes
Run the executable files:
```
./exer1a
```
```
./fork
```


![Alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5c/Flag_of_Greece.svg/255px-Flag_of_Greece.svg.png)

# Διαχείριση Διεργασιών με Fork και Wait στη Γλώσσα C

Για την ανάθεση εργασίας, κάντε κλικ στον σύνδεσμο:  
[Ανάθεση Εργασίας](Assignment/)

Για τον πηγαίο κώδικα, κάντε κλικ στον σύνδεσμο:  
[Κώδικας](Code/)

Για την αναλυτική τεκμηρίωση, κάντε κλικ στον σύνδεσμο:  
[Τεκμηρίωση](Documentation)

## Πληροφορίες Μαθήματος
- **Μάθημα**: [Λειτουργικά Συστήματα ΙΙ](https://ice.uniwa.gr/education/undergraduate/courses/operating-systems-ii/)
- **Εξάμηνο**: 4ο
- **Πρόγραμμα Σπουδών**: [UNIWA](https://www.uniwa.gr/)
- **Τμήμα**: [Πληροφορικής και Μηχανικών Υπολογιστών](https://ice.uniwa.gr/)
- **Εργαστηριακός Υπεύθυνος**: [Ψαρράς Νικόλαος](https://ice.uniwa.gr/emd_person/20879/)
- **Ακαδημαϊκή Χρονιά**: 2021-2022

## Πληροφορίες Φοιτητή
- **Όνομα**: Αθανασίου Βασίλειος Ευάγγελος
- **Αριθμός Μητρώου**: 19390005
- **Κατάσταση**: Προπτυχιακός Φοιτητής

## Τίτλος Ανάθεσης
**Τίτλος**: Δημιουργία και Διαχείριση Πολλαπλών Διεργασιών με Χρήση Fork και Wait

## Περιγραφή
Αυτή η εργασία αφορά την ανάπτυξη ενός προγράμματος σε γλώσσα C που χρησιμοποιεί τις κλήσεις συστήματος `fork()` και `wait()` για να δημιουργήσει και να διαχειριστεί ένα σύνολο διεργασιών με συγκεκριμένη ιεραρχία (δέντρο διεργασιών). Το πρόγραμμα επιδεικνύει επικοινωνία μεταξύ διεργασιών, συγχρονισμό διεργασιών, και εξετάζει πιθανά σενάρια όπου μπορεί να δημιουργηθούν ορφανές ή zombie διεργασίες.

Οι κύριοι στόχοι είναι:
- Δημιουργία συνολικά **επτά διεργασιών**, συμπεριλαμβανομένης της κύριας διεργασίας (P0), ακολουθώντας μια συγκεκριμένη δομή δέντρου.
- Διασφάλιση ότι η διεργασία P0 περιμένει τη διεργασία P1 να ολοκληρωθεί πριν αντικαταστήσει τον εαυτό της με την εντολή `cat`, η οποία εκτυπώνει τον πηγαίο κώδικα.
- Εφαρμογή συγχρονισμού διεργασιών, διασφαλίζοντας ότι οι διεργασίες παιδιών τερματίζονται με ελεγχόμενο τρόπο μέσω της χρήσης του `wait()` ώστε να αποτραπούν οι zombie διεργασίες.
- Διαχείριση μηνυμάτων μεταξύ διεργασιών, όπου η P1 πρέπει να λάβει ένα μήνυμα "hello from your child" από την P3.
- Επέκταση του προγράμματος ώστε η διεργασία P2 να δημιουργεί **N παιδιά** βασισμένα στην είσοδο του χρήστη, όπου κάθε παιδί τυπώνει το PID και το PPID του πριν τερματιστεί.

### Βασικά Μαθησιακά Αποτελέσματα:
- Κατανόηση και εφαρμογή των κλήσεων συστήματος `fork()` και `wait()`.
- Διαχείριση δημιουργίας διεργασιών και διασφάλιση του σωστού συγχρονισμού μεταξύ γονέων και παιδιών διεργασιών.
- Μάθηση της ιεραρχίας διεργασιών, επικοινωνίας μεταξύ διεργασιών, και τερματισμού διεργασιών.
- Έρευνα και συζήτηση της δημιουργίας ορφανών ή zombie διεργασιών και πώς να αποφεύγονται.

## Δομή Δέντρου Διεργασιών:
Το πρόγραμμα ακολουθεί την εξής ιεραρχία διεργασιών:
                (P0)
                / \
               /   \
              /     \
             /       \ 
            /         \
         (P1)        (P2)
          /           /|\
         /           / | \
        /           /  |  \
       /           /   |   \
    (P3)         (P4) (P5) (P6)

## Απαιτήσεις
- **Λειτουργικό Σύστημα**: Περιβάλλον βασισμένο σε Linux (ή συμβατό Unix-like OS).
- **Μεταγλωττιστής**: GCC (GNU Compiler Collection).
- **Κλήσεις Συστήματος**: `fork()`, `wait()`, `execv()`, και άλλες όπου απαιτείται.

## Εγκατάσταση και Χρήση
### 1. Κλωνοποίηση του Αποθετηρίου
Κατεβάστε το αποθετήριο στο τοπικό σας σύστημα αρχείων:
```
git clone https://github.com/Operating-Systems-2-aka-Uniwa/Fork.git
```
### 2. Μεταγλώττιση των πηγαίων κωδίκων
Μεταγλωττίστε τους πηγαίους κώδικες με τον μεταγλωττιστή gcc:
```
gcc -o exer1a exer1a.c
```
```
gcc -o fork fork.c
```
### 3. Εκτέλεση των κωδίκων
Εκτελέστε τα εκτελέσιμα αρχεία:
```
./exer1a
```
```
./fork
```


