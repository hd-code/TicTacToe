# TicTacToe

Dieses Projekt ist für die Studenten des ersten Fachsemesters 'Angewandte Informatik' an der Fachhochschule Erfurt. Die haben mich gebeten, einen Vortrag zum Thema 'Clean Code' zu halten.

In diesem Repo im Ordner `docs` befindet dich die PowerPoint Präsentation zum Vortrag.

Im Ordner `src` ist ein einfaches Spiel 'TicTacToe' zu finden. Es ist der bekannt Klassiker für zwei Spieler. Das Projekt ist in C++ implementiert. Gespielt wird mittels der Konsole.

Das Spiel ist mitunter etwas 'over-engineered'. Ich habe also sehr penibel die Dateien und Zuständigkeiten von einander getrennt, um die Prinzipien des 'Clean Code' aus dem Vortrag zeigen zu können.

## Installation

Für die folgende Routine wird der GCC-Compiler benötigt.

Dazu bitte die Konsole öffnen und folgende Befehle ausführen:

```shell
# 1. dieses Git Repo clonen
git clone https://source.ai.fh-erfurt.de/ha9384dr/TicTacToe.git

# 2. in den Projektordner wechseln
cd TicTacToe

# 3. das Projekt compilieren
make

# 4. compiliertes Projekt ausführen (Spiel starten)
./TicTacToe
```

### Installation mit Entwicklungsumgebung z.B. Visual Studio

Alternativ kann man das Projekt auch mit einer beliebigen Entwicklungsumgebung (IDE) compilieren und starten.

Dazu muss in der IDE ein neues leeres Projekt angelegt werden. Anschließend müssen alle Dateien in allen Unterordnern im Ordner `src` in das Projekt importiert werden.

Nun kann das Projekt in der IDE compiliert und ausgeführt werden.