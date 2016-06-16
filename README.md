# AMSMaze
Implementazione di un labirinto 3D mediante l'uso di OpenGL e glut.
- Progetto per l'insegnamento di Sistemi Multimediali
- Anno accademico 2015/2016
- Pezzutti Marco 1084411

Il labirinto viene creato mediante file di input che contiene nella prima riga le seguenti informazioni:
- numero righe;
- numero colonne;
- indice di riga dell'ingresso del labirinto;
- indice di colonna dell'ingresso del labirinto;
- indice di riga della posizione del giocatore;
- indice di colonna della posizione del giocatore;
- indice di riga dell'uscita del labirinto;
- indice di colonna dell'uscita del labirinto.
Le righe successive indicano la conformazione del labirinto dove con un 1 viene identificato un muro mentre con lo 0 un corridoio.
È possibile inserire file di input differenti da quello fornito, a condizione che venga mantenuta la struttura del file e che ingresso e uscita si trovino rispettivamente nella prima riga e nell'ultima.

Sono possibili 6 tipo di movimenti all'interno del labirinto, mappati con specifici tasti:
- w compie uno spostamento in avanti;
- a compie uno spostamento a sinistra;
- s compie uno spostamento indietro;
- d  compie uno spostamento a destra;
- q compie una rotazione verso sinistra;
- e compie una rotazione verso destra.
Prima di essere effettuato ogni spostamento viene controllato con lo scopo di evitare collisioni con muri e porte di ingresso e uscita.

È stata implementata una luce globale molto debole, che permette di avere una minima visione anche nelle parti più buie del labirinto, e una spotlight che simula la presenza di una torcia in mano al giocatore, di colore tendente al giallo e puntata leggermente verso il basso.
Sono state realizzate 5 diverse texture per muri, soffitto, pavimento e porte di ingresso e uscita con materiali diversi per aumentare il grado di realismo della scena.

Il gioco consiste nel trovare l'uscita dal labirinto entro lo scadere del tempo, fissato inizialmente a 300 secondi; se ciò non dovesse accadere il giocatore viene riportato nel punto iniziale, viene fatto ripartire il tempo con un aggiunta di 100 secondi.
Quando il giocatore trova l'uscita, indicata con una porta di color bronzo, diversa da quella di ingresso di color acciaio, il tempo si ferma e vengono fatte le congratulazioni all'utente a cui viene lasciata la possibilità di ispezionare il labirinto senza limiti di tempo.

La barra del titolo mostra costantemente informazioni rigurdanti il gioco:
- prima che venga fatto il primo spostamento:
  - nome dell'applicazione;
- durante il gioco:
  - il tempo rimanente per uscire;
  - la posizione del giocatore nel labirinto;
  - nome dell'applicazione;
- a gioco terminato:
  - congratulazioni all'utente;
  - secondi impiegati a trovare l'uscita nel tentativo corrente;
  - numero tentativi effettuati;
  - nome dell'applicazione;
