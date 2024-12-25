# YouTube_Video_Score_Calculator 🎬📊
Object Oriented Programming Project using Encapsulation , Inheritance , Polymorphism and Abstraction

# RO LANGUAGE 🇷🇴 :
Acest proiect calculează scorurile videoclipurilor dintr-o platformă de social media pe baza unui set de informații (ID, categorie, like-uri, dislike-uri, vizualizări). Scorurile sunt calculate atât în mod simplu, cât și avansat. Proiectul permite sortarea și analiza acestora pe baza mai multor criterii. 🔢

## Descrierea Cerințelor

### Comanda (a) - Sortarea Videoclipurilor 📈
Se sortează videoclipurile crescător în funcție de scorul simplu. Videoclipurile cu același scor vor fi sortate descrescător în funcție de numărul de dislike-uri.

- Se va calcula scorul simplu pentru fiecare videoclip conform formulei:
    SS = L * D + 1 - 1 / V
  
- Rezultatele vor fi afişate astfel:
- ID-ul videoclipului
- Scorul simplu, afişat cu exact două zecimale.

### Comanda (b) - Calculul Scorului Simplu Mediu 🧮
Se va calcula scorul simplu mediu al videoclipurilor și vor fi afişate doar videoclipurile care au scorul simplu mai mare decât media calculată.

### Comanda (c) - Actualizare și Adăugare Videoclipuri ✏️
Se vor citi videoclipuri până la **EOF**. Dacă există deja un videoclip cu același ID, se vor actualiza informațiile acestuia, iar dacă nu, acesta va fi adăugat.

### Comanda (d) - Sortare După Scorul Avansat 🏆
Videoclipurile vor fi ordonate crescător în funcție de scorul avansat calculat pe baza scorului simplu și a categoriei.
- Se va calcula scorul avansat pentru fiecare videoclip conform formulei:
    SA = SA * 0.75

## Descrierea Programului

Programul citește mai multe informații despre videoclipuri de la utilizator și efectuează diferite operațiuni pe baza comanda menționate mai sus. Pentru fiecare videoclip se citește ID-ul, categoria, numărul de vizualizări, numărul de like-uri și dislike-uri, iar apoi se calculează scorul simplu și avansat.

### Instructiuni de utilizare ⚙️

1. **Introducerea videoclipurilor**:
  - Programul va solicita introducerea unui număr de videoclipuri, urmat de informațiile fiecăruia.
  - Formatul fiecărei linii pentru un videoclip este:
    ```
    <ID film> <Tip Videoclip> <număr de vizualizări> <număr de like-uri> <număr de dislike-uri>
    ```

2. **Tipul Comenzii**:
  - După ce toate videoclipurile sunt citite, utilizatorul trebuie să introducă un caracter din intervalul `[a-d]` care indică comanda ce trebuie tratată:
    - **a**: Sortarea videoclipurilor după scorul simplu.
    - **b**: Afișarea videoclipurilor cu scorul simplu mai mare decât media.
    - **c**: Citirea videoclipurilor până la EOF, actualizarea celor existente și adăugarea celor noi.
    - **d**: Sortarea videoclipurilor după scorul avansat.

3. **Rezultatele**:
  - La final, programul va afișa rezultatele solicitate în funcție de comanda aleasă.

### Exemplar de Input:
3
vid1 Sport 120 60 10
vid2 Studiu 300 150 20
vid3 Animale 200 80 15
c
vid1 Sport 150 70 20
vid3 Animale 220 100 30
vid4 Studiu 400 200 40


### Exemplar de Output pentru cerința (a):
vid4 6.00
vid3 6.33
vid1 6.99
vid2 8.50

# EN LANGUAGE 🇬🇧 :

This project calculates the scores of videos from a social media platform based on a set of information (ID, category, likes, dislikes, views). The scores are calculated both simply and advanced. The project allows sorting and analyzing the videos based on various criteria. 🔢

## Requirements Description

### Command (a) - Sorting Videos 📈
The videos are sorted in ascending order based on the simple score. Videos with the same score will be sorted in descending order based on the number of dislikes.

- The simple score for each video will be calculated according to the formula:
    SS = L * D + 1 - 1 / V
  
- The results will be displayed as follows:
  - Video ID
  - Simple score, displayed with exactly two decimal places.

### Command (b) - Calculate the Average Simple Score 🧮
The average simple score of the videos will be calculated, and only the videos with a simple score higher than the calculated average will be displayed.

### Command (c) - Update and Add Videos ✏️
Videos will be read until **EOF**. If a video with the same ID already exists, its information will be updated; if not, it will be added.

### Command (d) - Sort by Advanced Score 🏆
The videos will be sorted in ascending order based on the advanced score calculated from the simple score and the category.
- The advanced score for each video will be calculated according to the formula:
    SA = SS * 0.75

## Program Description

The program reads multiple pieces of information about the videos from the user and performs different operations based on the commands mentioned above. For each video, the ID, category, number of views, number of likes, and dislikes are read, then the simple and advanced scores are calculated.

### Usage Instructions ⚙️

1. **Entering Videos**:
   - The program will ask for the number of videos, followed by the information for each video.
   - The format for each video line is:
     ```
     <Video ID> <Video Type> <number of views> <number of likes> <number of dislikes>
     ```

2. **Command Type**:
   - After all the videos are entered, the user needs to enter a character from the `[a-d]` range indicating which command should be processed:
     - **a**: Sort videos by simple score.
     - **b**: Display videos with a simple score higher than the average.
     - **c**: Read videos until EOF, update existing ones, and add new ones.
     - **d**: Sort videos by advanced score.

3. **Results**:
   - Finally, the program will display the requested results based on the selected command.

### Example Input:
3  
vid1 Sport 120 60 10  
vid2 Studiu 300 150 20  
vid3 Animale 200 80 15  
c  
vid1 Sport 150 70 20  
vid3 Animale 220 100 30  
vid4 Studiu 400 200 40

### Example Output for requirement (a):
vid4 6.00  
vid3 6.33  
vid1 6.99  
vid2 8.50
