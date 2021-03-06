# AMSMaze
Implementazione di un labirinto 3D mediante l'uso di OpenGL e glut per la parte grafica, OpenAL e alut per la parte sonora.
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

Nella seconda riga:
- indice di riga del primo allarme
- indice di colonna del primo allarme
- indice di riga del secondo allarme
- indice di colonna del secondo allarme

Le righe successive indicano la conformazione del labirinto dove con un 1 viene identificato un muro mentre con lo 0 un corridoio; con il numero 2 viene indicata la soluzione del labirinto mentre con il 5 la posizione di un allarme.
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
Sono state realizzate 6 diverse texture per muri, soffitto, pavimento, allarmi e porte di ingresso e uscita con materiali diversi per aumentare il grado di realismo della scena.

Sono stati aggiunti due sorgenti sonore che riproducono lo stesso suono e identificano un allarme da spegnere visibile all'utente mediante una casella del pavimento colorata di rosso.
Gli allarmi sono spazializzati aiutando l'utente a capire la distanza e la direzione da cui provengono facilitando la loro disattivazione che si compie posizionandosi sopra alla casella di allarme.

Il gioco consiste nel trovare l'uscita dal labirinto entro lo scadere del tempo, fissato inizialmente a 300 secondi; se ciò non dovesse accadere il giocatore viene riportato nel punto iniziale, viene fatto ripartire il tempo con un aggiunta di 100 secondi.
Affinché il giocatore possa uscire è necessario che tutti gli allarmi vengano trovati e disattivati.
Quando il giocatore trova l'uscita, indicata con una porta di color bronzo, diversa da quella di ingresso di color acciaio, il tempo si ferma e vengono fatte le congratulazioni all'utente a cui viene lasciata la possibilità di ispezionare il labirinto senza limiti di tempo.

La barra del titolo mostra costantemente informazioni rigurdanti il gioco:
- prima che venga fatto il primo spostamento:
  - il nome dell'applicazione;
- durante il gioco:
  - il tempo rimanente per trovare l'uscita;
  - la posizione del giocatore nel labirinto;
  - gli allarmi rimanenti da disattivare;
  - il nome dell'applicazione;
- a gioco terminato:
  - le congratulazioni all'utente;
  - i secondi impiegati a trovare l'uscita nel tentativo corrente;
  - il numero di tentativi effettuati;
  - il nome dell'applicazione.
