-- phpMyAdmin SQL Dump
-- version 4.1.14.8
-- http://www.phpmyadmin.net
--
-- Host: db584899029.db.1and1.com
-- Erstellungszeit: 13. Feb 2016 um 23:13
-- Server Version: 5.1.73-log
-- PHP-Version: 5.4.45-0+deb7u2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Datenbank: `db584899029`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `acts`
--

CREATE TABLE IF NOT EXISTS `acts` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=13 ;

--
-- Daten für Tabelle `acts`
--

INSERT INTO `acts` (`id`, `name`, `description`) VALUES
(3, 'II Mayas Erbe', 'Eva sagt Maya, dass sie eine Maya ist, und führt sie in den Wald, wo Maya nach den Spuren ihres Erbes suchen wird.\n\nDer erste Punkt ist eine Weggabelung, auf der ein Wegweiser die Richtungen ''Sicher'' und ''Gefahr'' anzeigt.\n\nMaya findet die 4 Tempel der Schutzgeister und erfährt ihre Geschichte. Sie gibt die Schutzgeisterseelen frei.\n\nSie lernt auch die 3 Waldgeister kennen und erfährt deren Geschichte.\n\nAm Ende des Aktes erlernt Sie die Transzendenz um zwischen den Welten zu reisen. Sie erfährt, dass die Statue im Dorf der Eingang zur Mayawelt ist. voller Vorfreude, ihren Vorfahren zu begegnen, begibt Sie sich in die Welt unter der Erde.\n\nDort angekommen erwartet Sie eine Katastrophe. Alles ist zerstört und die Freude ist verflogen.'),
(2, 'I Mayas Träume', 'Zu Hause angekommen, herrscht Stromausfall. Durch das Fenster kann Maya noch einiges erkennen, aber sie muss in den Keller und den Strom wieder einschalten. Das nächste Rätsel besteht daraus eine Lampe zu bauen um im Keller etwas erkennen zu können.\nIm Keller findet Maya ein Teleskop. Aus trotz möchte Maja dies benutzen, da es von ihrem Vater stammt. außerdem verspürt sie den Drang, mal wieder in die Sterne zu schauen. Das Teleskop ist aber nicht vollkommen funktionsfähig, Also muss Man es erst reparieren, eh man es benutzen kann.\n\nIst es erst mal Repariert, stellt man sich auf die Terasse und schaut in die Sterne. Man sieht die Planeten und kann jeden einzelnen davon betrachten und Maya sagt etwas dazu. Wenn man auf den Kometen klickt, entdeckt Maya, dass dieser in direktem Erdanflug ist. Sie erschrickt und denkt die Erde wird bald untergehen.\n\n-lustiger Monolog, irgendwas existenzielles oder so. Maya wiegt ihre Möglichkeiten ab und entscheidet erst einmal zu schlafen.\n\nAm Morgen wird sie von ihrer Mutter geweckt und erzählt ihr vom Weltuntergang. Die Mutter macht sich darüber lustig und nimmt es nicht ernst. Ironisch gibt sie den Tipp dies dem Bürgermeister zu erzählen und Maya möchte diesem nachkommen.\n\nMaya geht ins Dorf. Im Dorf kann man überall hingehen. Der Bürgermeister hat aber momentan ganz andere Probleme... In Gesprächen mit den Einwohnern des Dorfes wird Maya auf die Party des Bürgermeisters aufmerksam und nimmt sich vor Bürgerin der Woche zu werden um an den Bürgermeister in einem geeigneten Moment heran zu kommen. Dazu verkuppelt sie alles und jeden:\n\nDer Obstverkäufer verkauft kokosnüsse. Der Nussverkäufer findet, dass ihm das Verkaufsrecht daran zusteht. Man muss durch Dialoge und Diplomatie die Nuss zurück verhandeln (die beiden verkuppeln).\n\nFür die Lösung dieses Rätsels muss man sich zur Baustelle begeben um einen Polizisten vom Marktplatz weg zu locken. Dort beginnt ein weiterer Tagtraum, der allerdings unterbrochen wird, weil man vom Polizisten aufgeschreckt wird. Während des Tagtraums hat man sich in den verbotenen Bereich der Baustelle begeben und dort darf man nicht hin. Der Tagtraum schwindet und Maya steht auf der Baustelle.\n\nDie Katzen der Alten Frau und des Alten Mannes sind abgehauen. Die der alten Frau sitzt im Baumhaus auf dem Katzenbaum und die des Mannes sitzt im Brunnen fest. Man bringt die Katzen beide aufs Baumhaus und verkuppelt die alten.\n\nNachdem man die Katze des Alten Mannes aus dem Brunnen gefischt hat, taucht Mayas Vater auf. Er kommt vom Gutshaus und geht in Richtung Mayas Haus. In der Hand hält er das Teleskop. Maya sieht das Teleskop und ruft: ''Hey, das ist mein Teleskop''. Der alte mann ist ziemlich verwirrt und denkt er sei gemeint. Der Fokus der Sequenz geht auf die beiden. Der Alte mann sagt, sie sollte ihre Selbstgespräche leiser führen. Maya schreckt zusammen und dreht sich um. Die Sequenz zeigt wieder den kompletten Screen und Mayas Vater ist verschwunden.\nMaya ''Wo ist er hin?''\nAlter Mann: ''Wo ist wer hin? willst du etwa Geld von mir?''\n\nMaya hilft Steve den Antrag seiner Freundin anzunehmen.\n\nWenn Steve zur Statue geht und Maya hinterher, beginnt eine Sequenz. Die Statue sieht nicht so verwachsen aus und Mayas Vater redet mit Maya: ''Du musst mir versprechen auf sie aufzupassen...'' Steve reißt Maya aus dem Traum.\n\nDie Alte frau erscheint und gibt Maya ihre Einladung zur Party des Bürgermeisters.\n\n-harter schnitt-\n\nMaya ist auf der Party.\n\nAuf der Party begegnet Maya unter anderem Heinz, dem Busfahrer. Dieser ist auf Der Party um dafür zu sorgen, dass er einen Stellplatz auf dem Parkplatz bekommt. Der Platz, auf dem er gerade steht, ist nämlich scheinbar verflucht.\n\nnachdem Maya mit dem Busfahrer geredet hat, läuft ihr Vater durch den Raum. Maya beginnt auf ihn einzureden, doch der Busfahrer stoppt Sie und beginnt zu erklären, dass solche Aktionen in dieser Gesellschaft eher unerwünscht sind.\n\nMaya bittet des Bürgermeisters Frau um ihr Gehör. Die Bürgermeisterin flucht, weil ein paar gäste mehr gekommen sind und Sie die Sitzordnung komplett umstrukturieren muss. Ohne dass Maya ihre Hilfe anbietet, nimmt des Bürgermeisters Frau diese in Anspruch und ein kleines Logik-Minispiel beginnt.\n\nSchließlich kann man mit des Bürgermeisters Frau reden. Diese schickt Sie zur Psychologin.\n\nEine Sequenz beginnt. Die Psychologin erzählt vom inneren Gleichgewicht, das bei Maya nicht vorhanden ist. Sie verschreibt ihr Heilsteine und gibt ihr einige mit.\n\nMaya geht aus dem Haus der Psychologin und trifft Eva. Eva erzählt ihr nun, dass sie ein Maya ist.'),
(1, '0 Das Tutorial', 'Maya sitzt am Spielautomaten. Der erste Teil des Tutorials ist das Automatenspiel. Die Grafik ist verhältnismäßig schlecht. Maya kommentiert und führt so selbst durch das Tutorial. Sie gibt Anweisungen. \n\nsiehe: Rätsel - Mayas Schaum\n\nMaya hat genug gespielt und will nach Hause gehen. Sie geht zur Tür und hört eine Stimme: ''Was ist Los mit dir, Maya?''\n\nDie Umgebung verschwimmt und Maya sitzt im Café. Der Kellner redet mit ihr. Er geht auf ihre Stimmung ein und der Spieler erfährt, warum sich Maya mit ihrer Mutter gestritten hat. Es ist das alte Problem. Immer wieder versucht Maya etwas über ihren Vater in Erfahrung zu bringen, doch ihre Mutter bleibt stur.\n\nLetzten Endes bietet der Kellner einen Kaffee an. Man hat die Wahl anzunehmen oder abzulehnen.lehnt man ab, wird der Kaffee erneut angeboten. Der Kellner macht ihr klar, dass man in einem Café ist und wenn man so lange da bleibt, sollte man zumindest einen Kaffee bestellen. Der Dialog ist Endlos, bis man einen Kaffee bestellt.\nDer Kellner geht zur Kaffeemaschine um einen zu zapfen. Die Maschine ist aber Verstopft und Kaputt. Nun ist es an Maya, diese zu reparieren. Sie hat Zugang zu allen Räumen des Gebäudes: Küche, Besucherraum, Straße vor dem Café und Damentoilette. Nur auf die Herrentoilette traut sich Maya nicht.\n\nsiehe: Rätsel - Die Kaffeemaschine\n\nNachdem die Maschine repariert ist, ist das Tutorial endgültig beendet. Maya geht nach Hause.'),
(4, 'III Mayas Vermächtnis', 'Die Welt der Maya ist zerstört, aber das erste, was Maya bemerkt, ist die Aura eines Tagtraumes. Der Spieler bekommt also direkt einen Hinweis, dass es hier einen Tagtraum gibt. Bei Einstieg in den Tagtraum findet Maya eine Alltagssituation der Maya vor: Menschen unterhalten sich über banale Themen. Maya jedoch ist wieder Teil dieses Tagtraumes. Der Tagtraum ist Realer als je zuvor. Auf einmal bemerkt jemand der anderen, dass Maya dort steht und fragt sie, warum sie sich so heranschleicht. Er habe Sie noch nie gesehen. Der Spieler hat nun zum ersten Mal die Möglichkeit in den Tagtraumdialogen zu interagieren.\nNach dem Tagtraum ist Maya verwundert, dass es so real war und sie die Möglichkeit hatte selbst zu entscheiden.\n\nDurch die verbleibende Strahlung der Energiequelle hat Maya die Möglichkeit in den Tagträumen mit ihren Vorfahren zu kommunizieren. \n\nWenn Sie in einer Tagtraumsequenz den Screen wechelt, dann wacht sie nach dem Tagtraum auch in einem anderen Screen auf.\n\nDoch nicht jeder möchte Ihr glauben, dass sie aus der Zukunft kommt. und noch weniger glauben, dass in der Zukunft die Zerstörung herrscht.'),
(6, 'Spielmechaniken', 'Neben den üblichen Spielmechaniken eines Point ''n Click Adventure Spiels wird Mayas Traum über folgendes verfügen\n\nViele Spieler spielen ein Adventure spiel in mehreren Phasen. Wenn zwischen mehreren Spielsessions nun längere Pausen liegen, kann man sich zwar noch an Umrisse der Story erinnern, aber das Bewusstsein über die derzeitigen Aufgaben ist meist nicht mehr vorhanden. Aus diesem Grund wird jede Story- und Aufgaben relevante Situation in einem Artwork festgehalten.\n\nNun gibt es bei Laden eines Spielstandes die Möglichkeit, zu sehen was bisher geschah. Hierbei werden die Artworks die zu den jeweiligen Aufgaben gehören nacheinander gezeigt und die relevanten Dialoge dazu wiedergegeben.\n\nWeiterhin wird es die Möglichkeit geben die komplette Story mithilfe der Artworks noch einmal nachzuempfinden.'),
(7, 'Bilder Slideshow', 'noch nicht bearbeitet'),
(10, 'Prolog', 'Maya argumentiert mit ihrer Mutter.\nDie Kamera zoomt zurück und man sieht das haus, hört eine Treppe und die Tür geht auf und Maya geht auf die Straße. und begibt sich zum See.\nDort erscheint der Spieletitel.\n-harter Schnitt-\nMaya sitzt in der Spielhalle'),
(11, 'Unsortierte Ideen', 'Maya steht vor 2 Türen. Tür 1 führt in Raum 1. verlässt man Raum 1 steht man vor Tür 1. geht man in Tür 2, gelangt man auch in Raum eins. verlässt man diesen Raum, gelangt man wieder vor Tür 1.\n\nnach einigen Gesprächen bekommt Maya mit, dass dort Wohl das Teleport Event nicht richtig gesetzt wurde. Also gilt es, das richtige Event an die Tür zu binden. Das passiert mit Bindfaden und einem Zettel (dem Event). Nachdem dies geschehen ist, gelangt man durch Tür 2 in Raum 2.\n\n----------------------------------------------\n\nMaya braucht wichtige Informationen und kennt bereits den Menschen, der diese Wichtigen Informationen bereithält. Dieser ist jedoch Schauspieler und schon so in seinem Element, dass er verwirrende Antworten gibt, die keinen Sinn ergeben.\n\nHört man sich um, erfährt man, dass der Schauspieler ohne Script nicht weiß, was er sagen soll. Man muss also für verschiedene Antworten, die man erhalten möchte, verschiedene Scripte besorgen und dem Schauspieler übergeben, damit man an die Informationen gelangt.\n\n----------------------------------------------\n\nIm Tempel gibt es Unlogische Dimensionsverschiebungen man geht durch ein Labyrinth von größer und kleiner werdenden Räumen.\n\n----------------------------------------------\n\nSon Typ, der die ganze Zeit seinen Garten harkt, weil er pflanzen hasst.'),
(12, 'Meeeeeeeeega Plottwist', 'Maya erkennt am Ende des dritten Aktes, dass ihr Vater der 4. Schamane war. Sie erkennt, dass das Gleichgewicht nur Wiederhergestellt werden kann, wenn Sie als Erbe das Ritual vollendet und ihrer Bestimmung als Schutztier nachkommt und den Wals schützt.');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `acts_characters`
--

CREATE TABLE IF NOT EXISTS `acts_characters` (
  `actid` int(12) NOT NULL,
  `characterid` int(12) NOT NULL,
  PRIMARY KEY (`actid`,`characterid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `acts_characters`
--

INSERT INTO `acts_characters` (`actid`, `characterid`) VALUES
(1, 1),
(1, 13),
(2, 1),
(2, 2),
(2, 3),
(2, 4),
(2, 5),
(2, 6),
(2, 7),
(2, 8),
(2, 9),
(2, 13),
(2, 20),
(2, 21),
(2, 22),
(2, 23),
(2, 24),
(2, 25),
(2, 26),
(2, 27),
(2, 28),
(3, 1),
(3, 8),
(3, 14),
(3, 29),
(3, 30),
(3, 31),
(3, 32),
(3, 33),
(4, 29),
(10, 1),
(10, 9);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `acts_items`
--

CREATE TABLE IF NOT EXISTS `acts_items` (
  `actid` int(12) NOT NULL,
  `itemid` int(12) NOT NULL,
  PRIMARY KEY (`actid`,`itemid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `acts_items`
--

INSERT INTO `acts_items` (`actid`, `itemid`) VALUES
(1, 1),
(1, 2),
(1, 3),
(1, 4),
(1, 5),
(1, 6),
(1, 7),
(2, 8),
(2, 10),
(2, 11),
(2, 12),
(2, 13),
(2, 14),
(2, 15),
(2, 16),
(2, 17),
(2, 18),
(2, 19);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `acts_puzzles`
--

CREATE TABLE IF NOT EXISTS `acts_puzzles` (
  `actid` int(12) NOT NULL,
  `puzzleid` int(12) NOT NULL,
  PRIMARY KEY (`actid`,`puzzleid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `acts_puzzles`
--

INSERT INTO `acts_puzzles` (`actid`, `puzzleid`) VALUES
(1, 1),
(1, 5),
(2, 2),
(2, 3),
(2, 4),
(2, 6),
(2, 7),
(2, 8),
(2, 9),
(2, 11),
(11, 10);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `acts_screens`
--

CREATE TABLE IF NOT EXISTS `acts_screens` (
  `actid` int(12) NOT NULL,
  `screenid` int(12) NOT NULL,
  PRIMARY KEY (`actid`,`screenid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `acts_screens`
--

INSERT INTO `acts_screens` (`actid`, `screenid`) VALUES
(1, 1),
(1, 2),
(1, 3),
(1, 4),
(1, 17),
(1, 22),
(1, 23),
(2, 1),
(2, 2),
(2, 3),
(2, 4),
(2, 5),
(2, 6),
(2, 7),
(2, 8),
(2, 9),
(2, 10),
(2, 11),
(2, 12),
(2, 13),
(2, 14),
(2, 15),
(2, 17),
(2, 18),
(2, 19),
(2, 20),
(2, 21),
(2, 24),
(2, 25),
(2, 26),
(2, 27),
(2, 28),
(2, 29),
(2, 30),
(2, 31),
(2, 32),
(2, 33),
(2, 34),
(2, 35),
(2, 36),
(2, 37),
(2, 38),
(2, 40),
(10, 5),
(10, 9);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `characters`
--

CREATE TABLE IF NOT EXISTS `characters` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=34 ;

--
-- Daten für Tabelle `characters`
--

INSERT INTO `characters` (`id`, `name`, `description`) VALUES
(1, 'Maya', 'Maya ist 19 Jahre Alt. Ihr Leben ist vielseitig, doch eine Frage quält sie schon seit einiger Zeit. Sie möchte ihren Vater kennen lernen. Ihre Mutter möchte allerdings nichts darüber preisgeben. Sobald Maya sie darauf anspricht, eskaliert die Situation und ein nie enden wollender Streit entsteht.\n\nMaya hat gerade die Schule hinter sich und ist froh, dass sie nie wieder dorthin zurück muss.Dies ist der Grund, weshalb Sie im ersten Akt im Dorf bleibt und die Zufahrtsstraße zur Stadt nicht weiter als bis zur Baustelle betritt. Nichts liegt ihr ferner als wieder in die Nähe der Schule zu gelangen.\n\nFür Die Zukunft hat sie sich vorgenommen Förster zu werden. Sie Liebt Die Natur und ganz besonders die Bäume. In der Schule wurde Sie deswegen immer ausgelacht und auch Ihre Mutter sähe es lieber, wenn Maya einen Akademischen Beruf ausübt. Am liebsten hätte Sie nach der 10. Klasse aufgehört und direkt Förster gelernt. Doch Ihrer Mutter Bitten nachkommend erlangte Sie letztendlich das Abitur. Sie Hat schon früh begonnen Ihr wissen über Bäume auszubauen und so kann sie mit jedem Baum interagieren und etwas darüber erzählen.\n\nMaya hat hin und wieder Tagträume. Umgebungen verändern sich, Gegenstände verschmelzen und Unbekannte Personen treten auf, die Protagonistin im Mittelpunkt. \n\nIn 4 Schritten wird diese selbst zum Maya und erkennt, dass der Untergang der Zivilisation gar nicht so lange her ist. Ihr eigener Großvater hat zur Rettung der Welt und zum Untergang der Maya am 21.12.2012 beigetragen.\n\n Sie lernt, die Tagträume als Vergangenheitsereignisse zu sehen und nicht sich selbst sondern Vorfahren in den Mittelpunkt zu rücken.\n\n Sie lernt markante Orte als Tagtraumkatalysator zu erkennen und einen solchen zu erzeugen.\n Sie lernt Transzendent zu werden und in die Maya Welt zu reisen.\n Sie lernt durch eine Höhlenmalerei, dass die Vorfahren es geschafft hatten, sich als „Schamanen“ in Tiere zu verwandeln (der 5. Arm).\n\n Fähigkeiten:\n 1. Tagträume in 3. Person\n 2. Tagträume mehrmals erleben und hervorrufen\n 3. Transzendenz um zwischen den Reichen zu wechseln\n 4. Verwandlung zum Tier'),
(2, 'Eva', 'Eva hat ein nettes Lächeln und ist sehr zuvorkommend. Dies macht Sie zur idealen Kellnerin im Café. Sie wäre jedoch bei ihrer Arbeit viel Konzentrierter, wenn sie nicht ständig in Augenkontakt mit dem Koch kommen würde.\n\nEva ist Mayas beste Freundin. Seit dem Kindergartenalter sind die beiden miteinander befreundet. Eva ist allerdings ein wenig älter als Maya, was sie in gewisser Weise zu Mayas Schutzengel macht.\n\nvor einem Jahr hat Sie Mayas Vater kennen gelernt. Sie weiß also von den Maya, nicht aber von der Welt unter der Erde. Mayas Vater ist ihr an der Statue begegnet. (Dies ist die Sequenz, die Maya im ersten Akt Teilweise als Tagtraum erlebt.) Mayas Vater erzählt Eva, dass Maya wahrscheinlich Tagträume hat und dass sie eine Maya ist. Eva muss ihm versprechen, dass Sie Maya zum richtigen Zeitpunkt davon in Kenntnis davon setzen wird.'),
(3, 'Der Bürgermeister', 'Der Bürgermeister hat einen schwachen Willen. Wenn er in der Öffentlichkeit ist, ist dies zwar nicht zu merken, aber eigentlich ist seine Frau der Mann im Haus. Das Amt des Bürgermeisters bekleidet er also nur als eine Marionette.\n\nEr findet den Namen seiner Frau (Klothilde) zum schreien Komisch und würde am liebsten mit jemandem darüber lästern, doch sie hat es ihm verboten. So ist er verbittert und kann seinen Lippen kein lächeln abgewinnen.\n\nVor ein paar Jahren begann er eine Affäre mit der Psychologin, nachdem er dort heimlich eine Therapie erfolgslos begonnen hatte.'),
(4, 'Der Nussverkäufer', 'Der Nussverkäufer steht mit seinem Nussverkaufsstand auf dem Marktplatz des Dorfes. Im geheimen liebt er den Obstverkäufer.'),
(5, 'Der Obstverkäufer', 'Der Obstverkäufer steht mit seinem Obstverkaufsstand auf dem Marktplatz des Dorfes. Insgeheim Liebt er den Nussverkäufer.'),
(6, 'Steve', 'Steve ist Mayas bester Freund. Er ist ein wenig Paranoid, hat aber eine Freundin, die ihm sogar einen Antrag gemacht hat (s. Rätsel - gefährlicher Antrag)\n\nSteve fährt total auf Vanilleeis ab.'),
(7, 'Die Psychologin - Margitta Sens', 'Margitta Sens ist Psychologin. Jedoch diagnostiziert sie bei jedem Patienten das gleiche: Inneres Ungleichgewicht. Zu Heilen mit Heilsteinen.'),
(8, 'Mayas Vater', 'Mayas Vater war ein ausgewählter Schamane für das Ritual zur Verwandlung zum Schutztier. Er sabotierte das Ritual, weswegen die anderen Drei Schamanen seit je her als Waldgeister durch die Wälder ziehen.\n\nEr betrog sein Volk, um zwischen den Welten zu wandeln und die Energiequelle zu ergründen.\nWährend seiner Zeit über der Erde, lernte er Mayas Mutter kennen und zeugte Maya.'),
(9, 'Mayas Mutter', 'Mayas Mutter hat Mayas Vater in frühem Alter kennen gelernt. Er hat sehr wenig über sich Preis gegeben, doch sie hat ihn geliebt, wie keinen anderen. Kurz nachdem Maya zur Welt kam ist er verschwunden und hat nie wieder von sich hören lassen. Mayas Mutter hat über alle Kanäle nach ihm Gesucht, konnte ihn aber nirgends finden. Sie möchte nie wieder über ihn sprechen.\n\nMayas Mutter arbeitet in der Stadt.'),
(10, 'Die Köchin', ''),
(11, 'Der Zauberer', ''),
(12, 'Der Bärensammler', 'Der Bärensammler ist zu faul zum Jagen. Aus diesem Grund hat er es sich zur Aufgabe gemacht Bären zu sammeln. Da Bären aber hauptsächlich lebendig in freier Wildbahn anzutreffen waren, sammelte er stattdessen Beeren. Den Namen Bärensammler behielt er aber trotzdem. Von allen andern wurde er der Pilzsammler genannt.'),
(19, 'Der Seher', 'noch nicht bearbeitet'),
(13, 'Der Kellner', 'Netter Geselle. Kennt Maya, weil sie im Café regelmäßig ihren Kaffee trinkt. Er ist allerdings schon ein wenig paranoid.'),
(14, 'Die Urschamanin', 'Die Urschamanin wird Maya indirekt beibringen sich in ein Tier zu verwandeln. Von ihr erfährt der Spieler über das Ritual.'),
(15, 'Der Antagonist', 'Der Antagonist taucht nur in der Vergangenheit auf. Er ist ein Azteke. Die Azteken sind die zurück gelassenen Maya. Sie haben seit langem vergessen, woher Ihre Zivilisation entstammt. Der Antagonist allerdings hat auch die Fähigkeiten der Maya und geht seinen Tagträumen nach.'),
(16, 'Die Maya', 'Die Maya sind eine Zivilisation, die von den Zeitgenossen irrtümlich für Tod gehalten wird. Sie lebten jedoch seid eines in langer Vergangenheit liegenden Ereignisses im Untergrund. In den Sternen haben Sie die Besiedlung und Eroberung Amerikas vorhergesehen und Präventiv an einem Unterirdischen Lebensraum gearbeitet. Nach dessen Fertigstellung Verschwand die Zivilisation der Maya unter der Erde. Für die Geschichtsschreibung wird es später so aussehen, wie ein plötzlicher Untergang. Die Erdoberfläche konnte aber nur von solchen Maya verlassen werden, welche die Fähigkeit der Transzendens besaßen. Diese waren eine Art Akademikerklasse; die Elite. Die zurück gelassenen Arbeiter verendeten im Chaos, da diese keine Struktur mehr in ihrer Gesellschaft hatten. Aus den Überlebenden bildete Sich die Zivilisation der Azteken heraus. Natürlich Wollte von diesen niemand etwas mit den Maya zu tun haben und schließlich wurden die vereinzelten Geschichten um eine Frühere Zivilisation, die unter die Erde floh, immer mehr zu Legenden und Mythen.\r\n\r\nAm 21.12.2012 würde die Welt untergehen, so wurde es erkannt.  Schon Jahrhunderte vorher. Niemand jedoch, noch nicht einmal die Maya selbst wussten damals wodurch. Je näher dieses Datum allerdings rückte, desto mehr zeichnete Sich ab, was Ursache für die Apokalypse werden sollte.\r\n\r\nFür den Unterirdischen Lebensraum wurde eine Gewaltige Energiequelle benötigt. Diese besteht aus einem auf der Erde nicht bekannten Stoff. Sie ist so mächtig, dass Sie die ganze Welt zerstören könnte. Aus diesem Grund ist Ihre Existenz selbst unter den Maya ein Geheimnis. Nur ein einziger Maya weiß von Ihr und gibt dieses Geheimnis, sobald er seinen Tod kommen sieht, an einen vertrauenswürdigen seiner Art weiter. In der Umgebung der Energiequelle wurden so mächtige Zauber gewirkt, dass man die Maya Fähigkeiten nicht einsetzen kann. Verfolgt man also seine Ahnen bis zur Quelle, so verschwimmt dort der Tagtraum und man steht wieder in der Realität. \r\n\r\nDie Energiequelle wurde jedoch von den Maya unterschätzt. Sie war ein unbekannter Stoff von einem fremden Planeten. Eine Art Komet, der schon vor der Zivilisation dorthin gelangt war. Er war mit einer Unbekannten und scheinbar unendlichen Energie ausgestattet. Gleichzeitig hatte er aber eine Magnetische Wirkung auf seinen Ursprungsplaneten. Dieser näherte sich also unaufhaltsam der Erde. Die Maya, welche nun unter der Erde lebten, begannen immer mehr für sich selbst zu leben. An der Erdoberfläche Hatten Sie ständig die Planeten beobachtet und so wurde ihnen ständig klar, dass sie nur ein Winziger Teil des Ganzen waren. Unter der Erde fühlte sich nach ein paar Generationen jeder wie ein Held. Die Geschichten von der Oberfläche wurden zu Märchen. Niemand glaubte mehr daran. Einer der Maya war jedoch besessen von der Idee, dass es eine Oberfläche gibt. Er wollte seit seiner Kindheit sehen, was es dort oben alles zu sehen gibt. Also schaffte er es eines Tagen die Transzendenz zu erlernen und wechselte zwischen den Welten. Er hatte sich mit den Mythen über Planeten beschäftigt und konnte sich zusammenrechnen, was geschah, als er diesen einen Stern beobachtete, der langsam aber sicher immer größer wurde. Er zerstörte die Energiequelle der Maya um die Welt so vor einer Kollision zu bewahren. Damit Vernichtete er auch den gesamten Unterirdischen Lebensraum der Maya.\r\n'),
(17, 'Die Waldgeister', 'Die drei Waldgeister sind Drei der 4 Schamanen, die als nächste Schutztiere den Wald beschützen sollten. Das Ritual zur Verwandlung in Schutztiere wurde vom vierten Schamanen sabotiert und seit dem wandeln die drei als Waldgeister durch die Wälder mit dem Ziel, das Ritual zu vollenden.'),
(18, 'Die Kriegerin', ''),
(20, 'Alter Mann', 'Sitzt am Brunnen auf dem Marktplatz und jammert um seine Katze, die in den Strudel des Brunnens geraten ist. Er ist seit Jahren in die Alte Frau verliebt, hat sich aber nie getraut, ihr seine Liebe zu gestehen. Deswegen hat er sich die Katze angeschafft.'),
(21, 'Alte Frau', 'Steht vor dem Katzenbaum und Jammert um ihre Katze, die nicht mehr vom Baum runter kommt. Sie ist seit Jahren in den Alten Mann verliebt, hat sich aber nie getraut ihm ihre Liebe zu gestehen. Deshalb hat sie sich eine Katze angeschafft.\n\nSeit Jahren ist Sie Bürgerin der Woche.\n\nSie ist die einzige, die durchschaut hat, dass der Bürgermeister keine Kontrolle über das Dorf hat, sondern seine Frau die treibende Kraft hinter seinen Aktivitäten ist. Wer sollte sonst den Bau eines Shopping Centers auf historischen Ruinen bewirken wollen?\n\nDies erzählt sie Maya, als diese ihr vom drohenden Weltuntergang berichtet:\n\n''Dem Bürgermeister brauchst du damit nicht kommen. Wenn du wirklich Hilfe aus dieser Instanz haben möchtest, musst du an seine Frau herankommen.Ich bezweifle aber, dass sie Zeit für dich haben wird.''\n\nDialogoption erscheint ''Gibt es denn keinen Weg?''\n\n''Heute Abend ist die Wöchentliche Gutsparty. Ich habe Die Einladung dafür bereits erhalten. Ich denke nicht, dass du etwas in diesem Dorf bewirken kannst, das so großartig ist, dass du noch mit eingeladen wirst.'''),
(22, 'Katze der Alten Frau', 'Der Katze gefiel es bei der Alten Dame nicht mehr und Sie hat ein Jahr lang in jeder Freien Minute, die Sie nicht mit vorgetäuschtem Schnurren oder nach Fressen betteln verbracht hat, damit verbracht, dieses neue Zuhause zu errichten. Vor kurzem erst hat Sie ihrem Plan den Feinschliff verpasst und ist als großes Finale in ihr neues Baumhaus umgezogen.'),
(23, 'Katze des Alten Mannes', 'Die Katze des Alten Mannes ist eigentlich ein Kater. Er bekommt zu eisenhaltiges Futter und ist schon lange das Geheul seines Herrchens Leid. Dieser ist unsterblich verliebt und dies lässt er seinen Kater rägelmäßig wissen. Anders als sein Herrchen hat es der Kater allerdings geschafft seinem Herzchen seine Liebe zu offenbaren. Zusammen mit ihr hat er nun den Plan geschmiedet zusammen zu ziehen. Und zwar in das Katzenbaumhaus. Gerade, als er zum Treffpunkt mit seiner Liebe abhauen wollte, erwischte ihn sein Herrchen und rannte ihm hinterher. Um also das Herrchen auf eine Falsche Spur zu locken ging er einen Umweg über den Marktplatz und blieb dort im Strudel des Brunnen stecken. Aufgrund seiner Eisenhaltigen Ernährung und der daraus resultierenden Gewichts- und Trägheitsproblematik, kommt er von alleine aus dieser Situation nicht wieder heraus.'),
(24, 'Der Koch', 'Der Koch arbeitet im Café. Er ist ein Herzensguter Mensch, sehr sensibel. Auch, wenn sein Äußeres etwas anderes ausdrückt.\n\nEr fühlt sich immer wieder von Evas Annäherungsversuchen geschmeichelt, auch wen er nie in der Lage wäre, darauf einzugehen.'),
(25, 'Des Bürgermeisters Frau', 'Des Bürgermeisters Frau hat keinen Namen. Sie liebt es in Anonymität zu leben und die Schicksale des Dorfes in ihrer Hand zu halten. Sie hat ihren Mann vollkommen unter Kontrolle und somit auch die Politik des Dorfes. Sie Weiß auch, dass ihr Mann eine Affäre mit der Psychologin hat, unternimmt allerdings nichts dagegen, weil es sie amüsiert, dass ihr Mann denk, dass sie nichts ahnt.\n\nWenn sie gerade nicht damit beschäftigt ist, ihre Macht auszuüben, organisiert Sie Partys im Namen ihres Mannes und lädt Prominenz in ihr Haus ein. Unter anderem auch den Bürger der Woche. Dieser wird jede Woche vom Bürgermeister, also in Wahrheit von seiner Frau, bekanntgegeben. Bürger der Woche wird, wer besondere Verdienste im Sozialen Dorfleben zu verzeichnen hat.'),
(29, 'Die Schutzgeister / Schutztiere', 'Seit Menschengedenken haben die Maya die Aufgabe, den Wald zu schützen und somit die Natur im Gleichgewicht zu halten. Jede Generation bringt 4 Ausgewählte hervor, die durch ein Verwandlungsritual zu Schutztieren werden:\n\n - Eule\n - Bär\n - Schlange\n - Hirsch\n\nDiese bleiben so lange Schutztiere, bis die nächste Generation das Ritual vollziehen.\nSollten Sie sterben, wandern Sie als Schutzgeister durch die Wälder, bis ihre Aufgabe erledigt ist.\n\nDa das letzte Ritual sabotiert wurde, sind die 4 Schutztiere längst zu Schutzgeistern geworden und warten seit dem auf die Ankunft der neuen Schutztiere. Diese jedoch wandeln als Waldgeister durch die Welt.'),
(26, 'Das Auge', 'Ja, Das Auge ist ein Charakter. Es gibt komische Laute von sich, die meistens keinen Sinn ergeben, hin und wieder kann man aber satanische Botschaften darin erkennen. spielt man das gesagte Rückwärts ab, versteht man die Laute: Ich hasse Spiegel.'),
(27, 'Heinz', 'Heinz kann uns keiner nehmen...\n\nHeinz ist Busfahrer. Seit 30 Jahren lebt er nun schon auf der Straße. Er fährt und führt den Verkaufsbus.'),
(28, 'Der Polizist', 'Der Polizist steht auf dem Marktplatz. Er ist derjenige, der Maya von der Baustelle wirft. im übertragenen Sinne.'),
(30, 'Hirschgeist', 'noch nicht bearbeitet'),
(31, 'Eulengeist', 'noch nicht bearbeitet'),
(32, 'Bärengeist', 'noch nicht bearbeitet'),
(33, 'Schlangengeist', 'noch nicht bearbeitet');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `characters_items`
--

CREATE TABLE IF NOT EXISTS `characters_items` (
  `characterid` int(12) NOT NULL,
  `itemid` int(12) NOT NULL,
  PRIMARY KEY (`characterid`,`itemid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `characters_items`
--

INSERT INTO `characters_items` (`characterid`, `itemid`) VALUES
(1, 8),
(8, 8),
(24, 2),
(24, 10),
(26, 13),
(29, 20),
(29, 21),
(29, 23),
(29, 25),
(30, 21),
(31, 20),
(32, 23),
(33, 25);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `characters_puzzles`
--

CREATE TABLE IF NOT EXISTS `characters_puzzles` (
  `characterid` int(12) NOT NULL,
  `puzzleid` int(12) NOT NULL,
  PRIMARY KEY (`characterid`,`puzzleid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `characters_puzzles`
--

INSERT INTO `characters_puzzles` (`characterid`, `puzzleid`) VALUES
(1, 8),
(4, 6),
(5, 6),
(6, 8),
(6, 9),
(7, 8),
(13, 1),
(20, 4),
(20, 8),
(21, 7),
(21, 8),
(22, 7),
(24, 1),
(26, 8),
(27, 8),
(27, 9),
(28, 6);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `characters_screens`
--

CREATE TABLE IF NOT EXISTS `characters_screens` (
  `characterid` int(12) NOT NULL,
  `screenid` int(12) NOT NULL,
  PRIMARY KEY (`characterid`,`screenid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `characters_screens`
--

INSERT INTO `characters_screens` (`characterid`, `screenid`) VALUES
(1, 22),
(2, 33),
(3, 15),
(4, 15),
(4, 20),
(5, 15),
(5, 19),
(6, 15),
(6, 17),
(6, 18),
(6, 19),
(6, 20),
(6, 21),
(6, 24),
(6, 25),
(6, 26),
(6, 33),
(6, 35),
(7, 36),
(7, 37),
(7, 38),
(8, 33),
(13, 4),
(13, 22),
(20, 15),
(20, 26),
(21, 26),
(22, 27),
(23, 27),
(24, 2),
(27, 25),
(28, 15),
(28, 35),
(30, 49),
(31, 46),
(32, 47),
(33, 48);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `items`
--

CREATE TABLE IF NOT EXISTS `items` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=26 ;

--
-- Daten für Tabelle `items`
--

INSERT INTO `items` (`id`, `name`, `description`) VALUES
(1, 'Schraubenzieher', 'Befindet sich aus unerfindlichen Gründen auf der Herrentoilette im Café. Liegt allerdings zu hoch, um mit bloßen Händen ran zu gelangen. Wird benötigt um die Kaffeemaschine zu reparieren.'),
(2, 'Pfannenwender', 'Hängt in der Küche des Cafés. Der Koch hütet dieses Werkzeug sehr.\n\nWird benötigt um die Kaffeemaschine zu öffnen und den Hocker zu reparieren.'),
(3, 'Edding', 'Ein Gast hat ihn im Café liegengelassen, weil er leer ist. Er liegt auf einem der Tische vor dem Café neben benutztem Geschirr, dass noch nicht abgeräumt wurde.\n\nWird benötigt, um auf die Herrentoilette zu gelangen.'),
(4, 'Tasse', 'Liegt schief in der Kaffeemaschine. Wenn man die Maschine repariert, nimmt man sich die Tasse raus und steckt sie sich heimlich ins Inventar.\n\nWird benötigt, um die Tassenlampe zu bauen.'),
(5, 'Hocker', 'Liegt kaputt auf der Damentoilette umher. Ein Bein fehlt.\n\nWird benötigt um an den Schraubenzieher zu gelangen.'),
(6, 'Schaumbad', 'liegt im Bad (Automatenspiel) auf dem Boden. Wird benötigt um im Tutorial ein Schaumbad zu nehmen. Die Dose ist verstopft.'),
(7, 'Messer', 'Liegt aus unerfindlichen Gründen in der Badewanne.\n\nWird benötigt, um das Schaumbad aufzuschneiden.'),
(8, 'Teleskop', 'Das Teleskop gehörte einst Mayas Großvater. Es liegt seit Ewigkeiten im Keller. Es ist mittlerweile ziemlich kaputt. Ein Bein des Stativs fehlt. Ein Spiegel und eine Linse sind zerbrochen.\n\nWird benötigt um Mayas Wunsch nachzukommen, mal wieder in die Sterne zu sehen.'),
(9, 'Kaugummi', 'Derselbe Gast, der den Edding auf dem Tisch liegen gelassen hat, hat auch seinen Kaugummi unter den Tisch geklebt.\n\nWird benötigt um den Hocker zu reparieren indem man den Pfannenwender mit Dem Kaugummi als viertes Beim anklebt.'),
(10, 'Feuerzeug', 'Liegt in der Küche neben einer der Pfannen.\n\nWird benötigt um den Koch mit einer Brennenden Pfanne abzulenken und so an den Pfannenwender zu kommen.\n\nWird benötigt, um den Edding zu verrußen und ihn so wieder zum Schreiben zu bringen.'),
(11, 'Lesebrille der Mutter', 'liegt im Zimmer der Mutter auf dem Nachtschrank. Wird benötigt um das Teleskop zu reparieren.'),
(12, 'Kerze', 'Die Kerze steht im Café auf dem Tresen. Sie vermittelt ein letztes bisschen Romantik. Eva hat sie dort aufgestellt. Sie hatte gehofft, dass der Koch darauf aufmerksam wird. In gewisser weise wird er auch darauf aufmerksam. Maya nimmt die Kerze und verdirbt ein Gericht mit dem Feuer.'),
(13, 'Seitenspiegel des Verkaufsbusses', 'Der Seitenspiegel muss für die Rätsel gefährlicher Antrag und Das Glasauge vom Verkaufsbus entfernt werden. Damit wird Das Auge zur Strecke gebracht.'),
(14, 'Schaufel', 'Sie befindet sich im Gartenschuppen. Mit ihr kann man im Sandkasten des Spielplatzes graben und findet diverse Gegenstände, bis man letztenendes auf Öl stößt'),
(15, 'Katzenhalsband', 'Man findet es, wenn man im Sandkasten schaufelt.'),
(16, 'Kneifzange', 'findet man im Sandkasten. Man muss damit den Draht von der Schaukel schneiden.'),
(17, 'Batterie', 'findet man beim schaufeln im Sandkasten. Wird zum betreiben der Spule benötigt.'),
(18, 'Draht', 'Hängt an der Schaufel, bis man ihn mithilfe der Kneifzange dort entfernt und aus ihm eine Spule wickelt'),
(19, 'Rasenmäher', 'Der Rasenmäher steht im Schuppen und muss nach draußen geschleppt werden, damit man mit dem sägeblatt die Spule wickeln kann'),
(20, 'Feder', 'noch nicht bearbeitet'),
(21, 'Geweiende', 'noch nicht bearbeitet'),
(22, 'Hasenpfote', 'noch nicht bearbeitet'),
(23, 'Bärenkralle', 'noch nicht bearbeitet'),
(24, 'Scorpionstachel', 'noch nicht bearbeitet'),
(25, 'Schlangenzahn', 'noch nicht bearbeitet');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `items_puzzles`
--

CREATE TABLE IF NOT EXISTS `items_puzzles` (
  `itemid` int(12) NOT NULL,
  `puzzleid` int(12) NOT NULL,
  PRIMARY KEY (`itemid`,`puzzleid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `items_puzzles`
--

INSERT INTO `items_puzzles` (`itemid`, `puzzleid`) VALUES
(1, 1),
(2, 1),
(3, 1),
(4, 1),
(4, 2),
(5, 1),
(6, 5),
(7, 5),
(8, 3),
(10, 1),
(10, 2),
(11, 3),
(12, 1),
(13, 8),
(13, 9),
(14, 11),
(15, 4),
(15, 7),
(16, 11),
(17, 4),
(18, 11),
(19, 11);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `items_screens`
--

CREATE TABLE IF NOT EXISTS `items_screens` (
  `itemid` int(12) NOT NULL,
  `screenid` int(12) NOT NULL,
  PRIMARY KEY (`itemid`,`screenid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `items_screens`
--

INSERT INTO `items_screens` (`itemid`, `screenid`) VALUES
(1, 1),
(2, 2),
(2, 14),
(3, 17),
(4, 4),
(5, 3),
(6, 23),
(7, 23),
(8, 14),
(9, 17),
(11, 11),
(13, 24),
(13, 33),
(14, 21),
(14, 31),
(14, 32),
(15, 21),
(16, 21),
(16, 30),
(17, 15),
(17, 21),
(18, 21),
(18, 30),
(19, 30),
(19, 32);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `places`
--

CREATE TABLE IF NOT EXISTS `places` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Daten für Tabelle `places`
--

INSERT INTO `places` (`id`, `name`, `description`) VALUES
(1, 'Das Café', ''),
(2, 'Mayas Haus', ''),
(3, 'Das Dorf', 'Der Grundriss des Dorfes ist ein geheimes Mayasymbol.'),
(4, 'Das Haus der Psychologin', ''),
(7, 'Die Spielhalle', 'noch nicht bearbeitet'),
(9, 'Der Wald', 'Der Wald des Zweiten Aktes');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `puzzles`
--

CREATE TABLE IF NOT EXISTS `puzzles` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Daten für Tabelle `puzzles`
--

INSERT INTO `puzzles` (`id`, `name`, `description`) VALUES
(1, 'Die Kaffeemaschine', 'Die Kaffeemaschine ist überdimensional groß. Sie besteht aus Tresen und Wand. Maya muss den Tresen öffnen. Dafür benötigt sie einen Hebel. Diesen Hebel bekommt Sie in der Küche. Sie muss den Koch ablenken. Dies macht sie, indem Sie die Kerze vom Tresen nimmt und Feuer in einer Pfanne legt. Sie informiert denn Koch über den Brand und dieser gibt den Weg zum Pfannenwender frei. Hat Maya den Tresen geöffnet, muss sie dort eine falsch liegende Tasse herausnehmen. Sie bemerkt, dass die Zahnräder nicht ganz fest sind. Der Kellner verrät ihr, dass er auf der Herrentoilette einen Schraubenzieher gesehen hätte. Er selbst habe aber keine Zeit diesen zu holen, da sonst die Gäste gehen würden ohne zu zahlen. Also muss Maya selbst einen Weg finden. Sie schämt sich aber als Mädchen auf die Herren Toilette zu gehen, also muss sie sich einen Edding holen, den Cafégäste vor dem Café auf einem Tisch liegen gelassen haben. Mit diesem Edding malt sie dem Herren auf dem Schild Der Herrentoilette einen Rock und schon hat Sie keine Hemmungen mehr, hinein zu gehen. Auf der Herrentoilette liegt tatsächlich Ein Schraubenzieher, allerdings in einer höhe, an die Maya nicht Ran kommt. Auf der Damentoilette befindet sich ein kleiner Hocker, der allerdings Kaputt ist. Maya Repariert diesen Hocker, indem Sie den Pfannenwender in einen Zerkauten Kaugummi von vor dem Café eintaucht und ihn dann an den Hocker klebt. diesen benutzt sie  um an den Schraubenzieher auf der Herrentoilette zu gelangen. Sie Zieht Die Zahnräder fest und Die Kaffeemaschine ist wieder funktionstüchtig. Maya redet mit dem Kellner. Dieser Bittet Sie, ihm den Schraubenzieher wiederzugeben.'),
(2, 'Die Tassenlampe', 'Maya ist allein zu Haus und es ist dunkel. Der strom scheint ausgefallen zu sein. Der Stromkasten ist im Keller, Maya traut sich im Dunkeln aber nicht hinunter. Sie muss sich also eine Lampe bauen.\nSie nimmt sich die Tasse aus dem Café und schüttet Alkohol hinein. Der Alkohol kommt aus dem Alkoholgeheimversteck im Flur hinter dem Schuhschrank.\nIm Schuhschrank stehen massig schuhe. Jedes Paar hat eine besondere Bedeutung für Maya und nur eines ist wertlos genug, einen Schnürsenkel daraus zu entfernen und ihn für die Tassenlampe zu nutzen.'),
(3, 'Das Teleskop', 'Der Rahmen des Teleskopes ist zwar robust und nahezu unzerstörbar, aber die Linse und der Spiegel sind Kaputt. Außerdem scheint das Stativ nicht mehr zu halten. Die Einrastvorrichtung eines Fußes scheint nicht mehr zu funktionieren.\r\nMaya muss einen Spiegel und eine Lupe finden und diese zurechtschneiden.\r\nDas Stativ repariert Sie mit einem winzigen Keil.\r\nNun muss Sie das Stativ nur noch an der richtigen Stelle Platzieren und das Teleskop anbringen (eventuell Minispiel mit Schrauben, muttern und sich drehenden einrastenden Ebenen).'),
(4, 'Die Katze im Brunnen', 'noch nicht bearbeitet'),
(5, 'Mayas Schaum', 'Das Automatenspiel ist wie folgt aufgebaut:\n\nMan spielt einen Jungen. Dieser steht im Bad und möchte ein Schaumbad nehmen. Das Schaumbad liegt auf dem Boden. Es ist verstopft. Wenn man es aufhebt, muss man es mit dem Messer kombinieren, dass man aus der Badewanne nimmt. Danach kann man das Schaumbad in die Badewanne gießen. Natürlich alles auf einmal, denn durch die Interaktion mit dem Messer ist die Tube so beschädigt, dass man sie nicht mehr zurück ins Inventar legen kann.\nDas Wasser kann man erst aufdrehen, wenn man den Abfluss verschlossen hat.\nDurch die Hohe Menge an Schaumbad wird das ganze Badezimmer mit Schaum gefüllt. Das Level ist geschafft.'),
(6, 'Offensichtliche Liebe', 'Der Obstverkäufer verkauft Kokosnüsse.\nDer Nussverkäufer sieht sich als Verkaufsrechtinhaber für Kokosnüsse.\nMaya redet mit dem Nussverkäufer. Dieser sagt, er würde sich die Kokosnuss holen, wenn denn der Polizist nicht zusähe. Maya schlägt vor, den Polizisten abzulenken.\nMan geht zur Baustelle und hat einen Tagtraum. In diesem wird etwas zerstört. Der Polizist folgt Maya und reißt sie aus dem Traum. Sie hat aber tatsächlich etwas zerstört. Maya muss gehen, aber der Polizist ist damit beschäftigt aufzuräumen.\nIn der Zwischenzeit versuchte der Nusshändler die Nüsse zu klauen. Der Obsthändler aber, erwischte ihn. Kehrt man nun zum Marktpatz zurück, sieht man den Nussverkäufer am Obststand mit einer Hand kurz vor der Kokosnuss und den Obstverkäufer, wie er den Nussverkäufer am Arm hält. Die Taube, die während des Kaffemaschinenrätsels in Mayas Inventar Geflattert ist, fliegt nun automatisch heraus. Die Glocken des Gutshauses beginnen zu läuten.\nMaya muss nun einen Mistelzweig über die beiden halten. auf einmal beginnt es über den beiden und NUR über den beiden zu schneien. Wie ein Heiligenschein tut sich ein Kreis auf und es beginnt in leichten flocken. Dazu Orgelmusik. Dann aprupter Schluss der Musik und die Gesamtheit der vorhandenen Schneemassen ergießt sich über den beiden. Diese fangen an zu zittern und sich zu umarmen.\nMaya sammelt die Kokosnuss aus dem Schnee, teilt diese und bietet jedem eine hälfte an. ''und nun: seid fruchtbar und mehret euch!'''),
(7, 'Die Katze im Baum', 'noch nicht bearbeitet'),
(8, 'Das Glasauge', 'Maya muss während der Rätsel der beiden Katzen auch deren Eigentümer zusammenbringen. Dies wird nicht ganz einfach, denn im Zuge der Rettungsaktion, die der alte Mann bereits unternommen hatte, um seine Katze aus dem Brunnen zu bergen, hat er sein Glasauge verloren. Und so traut er sich nie und nimmer unter die Augen der alten Frau. Er erzählt Maya allerdings von seiner Liebe zu ihr. Eigentlich erzählt er es seiner Katze. Aber die ist so weit entfernt (im Brunnen), dass er es so laut erzählt, dass Maya es hören kann. Es gibt eine bestimmte dialog-option, die ihn dazu bringt mit seiner Katz über die Alte frau zu reden. So lange die Katze bei ihm ist, tuschelt er nur, aber nun redet er laut. Maya weiß also, was Sache ist und versucht dies der alten Frau beizubringen. Diese will ihr aber nicht glauben.\n\nMaya weiß, dass das Auge Geräusche von sich gibt und bittet Steve um ein Aufnahmegerät. Damit nimmt sie die Geräusche des Auges auf und bringt Sie zurück zu Steve. Der kann mit den Geräuschen nichts anfangen. Wohl aber die Psychologin. Sie ist geübt darin, anderer Leute Worte im Mund umzudrehen. Sie hört sofort die Konnotation des gesagten und gibt den Tipp, das Aufnahmegerät rückwärts abzuspielen. Sie gibt das Gerät Steve und dieser hört sich an, was das Auge zu ''sagen'' hat. Er ist allerdings so paranoid, dass er die Kassette im Aufnahmegerät zerstören möchte. Beim Aufmachen des Kassettendecks fällt ihm ein Kaugummi entgegen. Diesen schenkt er Maya. \n\nMaya muss sich also einen Spiegel verschaffen. Man montiert diesen vom Verkaufsbus ab. Auch das ist nicht so leicht, denn dafür muss man den Verkäufer, Heinz, erst einmal ablenken. Und zwar indem man den Kaugummi in das Eisfach klebt und Steve Das Himbeereis empfiehlt. Den Spiegel hält man dem Auge an der Statue vor. Daraufhin zerbricht der Spiegel und das Auge wird zu einem Glasauge und Maya kann es sich mitnehmen.\nMit dem Glasauge kann Sie nun zur Alten Dame gehen und so tun, als könne sie darin die Wahrheit erkennen, um es danach dem alten Mann zu geben, der es als passendes Ersatzteil für seinen brüchigen Körper akzeptiert.'),
(9, 'gefährlicher Antrag', 'Steve hat eine Freundin. Sie sind total verliebt in einander und Sie konnte es nicht abwarten, dass er ihr einen Antrag macht. Also nahm sie die Sache selbst in die Hand. Sie macht ihm einen Antrag und wartet seitdem auf eine Antwort.\n\nEr nämlich hat leicht Paranoide Züge. Er möchte so gern heiraten, traut sich aber nicht, den Ring aufzusetzen. Aus einem guten Grund: Das Auge sieht alles. Aus diesem Grund flieht er nach dem man ihn das erste mal angesprochen hat immer wieder auf einen anderen, zufälligen Screen.\n\nAllerdings gibt er Maya eine Pfeife, die Sie benutzen soll, falls sie sich mit ihm unterhalten möchte.\n\nEr versteckt sich vor dem Auge. Maya muss ihn also, nachdem Sie das Auge ''besiegt'' hat, davon überzeugen, dass es wirklich nicht mehr existiert. Was sich als schwierig erweist, denn so einfach kommt er nicht aus seiner Deckung.\n\nDer zerbrochene Spiegel reicht nicht, ihn zu überzeugen und auch das Glasauge könnte ein herkömmliches sein. Er muss also selbst zur Statue gelangen.\n\nSteve hat die Grundsätze stets 2 Querstraßen (Screens) weiter zu gehen und niemals dahin zurückzukehren, wo er vorher war. Nun müssen weitere Wege ausgeschlossen werden. Er hat ein Problem mit sich liebenden Wesen. Dies veranschaulicht ihm die Ausweglose Situation, in der er sich befindet.\n\nAlso muss Maya erst die Verkuppelungen abschließen: die beiden Verkäufer, die beiden Alten, die beiden Katzen. Er merkt von selbst wo sich Pärchen aufhalten, wenn er in einen solchen Screen gelaufen ist, dann wird er dort danach nicht mehr hinlaufen. (ToDo: Die Pärchen müssen also so platziert werden, dass nur gewisse Wege in Frage kommen).\n\nMaya überzeugt ihn dann, dass das einzig wahre Versteck der Wald sein wird. Er sieht das nicht so, allerdings bleibt ihm bei den ganzen Pärchen nichts anderes mehr übrig und er flieht in den Wald.\n\nNun gilt es den Weg zu versperren. Maya Platziert die Palmen-Attrappe auf dem Alternativen Weg. Die Palmen-Attrappe hat sie vom Obsthändler bekommen. Nachdem Sie den Streit um die Kokusnüsse geschlichtet hatte, wurde ihr die Palmen-Attrappe überlassen. Allerdings ist sie so groß, dass man sie erstmal stehen lassen muss. Man begibt sich also zum Obst verkaufsstand und schleift die Palme zu dem Stück weg, den man versperren möchte. Dabei muss man allerdings einen Umweg gehen, denn sobald man den Screen mit Steve betritt, flieht er.'),
(10, 'Das Gleichgewicht', 'An irgendeinem Ort des Spieles findet Maya eine Waage. Diese Waage muss ins GLEICHGEWICHT gebracht werden. Dieses Minispiel kann man durch klicken auf die Waage beginnen. Es lässt sich auch wieder abbrechen. Die daneben liegenden Gegenstände lassen sich auf die Waagenschalen ziehen, führen aber in keiner Kombination zum erwünschten Gleichgewicht. Lösung ist es das Minispiel zu starten, indem man die Heilsteine mit der Waage kombiniert. Dann nämlich liegen die Heilsteine neben der Waage und man kann alle anderen gegenstände beliebig auf der Waage platzieren, solange man die Heilsteine mit rauf legt.'),
(11, 'Die Spule', 'noch nicht bearbeitet');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `puzzles_screens`
--

CREATE TABLE IF NOT EXISTS `puzzles_screens` (
  `puzzleid` int(12) NOT NULL,
  `screenid` int(12) NOT NULL,
  PRIMARY KEY (`puzzleid`,`screenid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `puzzles_screens`
--

INSERT INTO `puzzles_screens` (`puzzleid`, `screenid`) VALUES
(1, 1),
(1, 2),
(1, 3),
(1, 4),
(1, 17),
(2, 5),
(2, 6),
(2, 7),
(2, 8),
(2, 9),
(2, 10),
(2, 11),
(3, 5),
(3, 6),
(3, 7),
(3, 8),
(3, 9),
(3, 10),
(3, 11),
(3, 12),
(3, 13),
(3, 14),
(4, 15),
(5, 23),
(6, 15),
(6, 19),
(6, 20),
(7, 26),
(7, 27),
(8, 15),
(8, 24),
(8, 25),
(8, 26),
(8, 33),
(9, 15),
(9, 17),
(9, 18),
(9, 19),
(9, 20),
(9, 21),
(9, 24),
(9, 26),
(9, 33),
(9, 35),
(11, 21),
(11, 30),
(11, 31),
(11, 32);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `screens`
--

CREATE TABLE IF NOT EXISTS `screens` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `description` text NOT NULL,
  `placeid` int(12) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=50 ;

--
-- Daten für Tabelle `screens`
--

INSERT INTO `screens` (`id`, `name`, `description`, `placeid`) VALUES
(1, 'Die Herrentoilette', '', 1),
(2, 'K&uuml;che', '', 1),
(3, 'Die Damentoilette', '', 1),
(4, 'Der Besucherraum', '', 1),
(5, 'Flur im Erdgeschoss', '', 2),
(6, 'Flur im Obergeschoss', 'noch nicht bearbeitet', 2),
(7, 'K&uuml;che', '', 2),
(8, 'Bad', 'Kommentar von Seb: \nÄhnelt dem Effekt des Behandlungszimmers der Psychologin zu sehr. Die Wirkung im Behandlungszimmer sollte einzigartig sein.', 2),
(9, 'Wohnzimmer', '', 2),
(10, 'Mayas Zimmer', 'Auf dem Schreibtisch liegt Mayas Abiturzeugnis. Bei Interaktion hält Maya einen Dialog zum Thema die Aussagekraft von Zahlen über die Reife eines Menschen.\n', 2),
(11, 'Mayas Mutter Zimmer', 'Auf dem Nachttisch liegt die Lesebrille der Mutter.', 2),
(12, 'Autogarage', '', 2),
(13, 'Speisekammer', '', 2),
(14, 'Keller', '', 2),
(15, 'Marktplatz', 'Auf dem Marktplatz findet das Leben des Dorfes statt. Im eigentlichen Sinne ist er die Auffahrt des Gutshauses. Der Bürgermeister ist also stets zugegen und beobachtet das geschehen. Auf dem Marktplatz stehen die Beiden Verkaufsstände: der Nussverkauf und der Obstverkauf. In der Mitte befindet sich ein Brunnen, an dem ein Alter Mann sitzt. Die Katze des Alten Mannes ist in den Strudel des Brunnens Geraten. Löst man die Beiden Katzenrätsel (''Die Katze im Brunnen'' und ''Die Katze im Baum''), liegen der alte Mann und die Alte Frau sich vor dem Brunnen in den Armen. Durch den nahen Verlust ihrer Katzen haben Sie sich gefunden.', 3),
(17, 'Vor dem Café', 'noch nicht bearbeitet', 3),
(18, 'Vor dem Gutshaus', 'noch nicht bearbeitet', 3),
(19, 'Obstverkaufsstand', 'Der Obststand wird vom Obstverkäufer geführt.', 3),
(20, 'Nussverkaufsstand', 'noch nicht bearbeitet', 3),
(21, 'Spielplatz', 'noch nicht bearbeitet', 3),
(22, 'Spielhalle', 'noch nicht bearbeitet', 7),
(23, 'Badezimmer (Automatenspiel)', '', 7),
(24, 'Vor dem Bus-Shop', 'vor dem Bus-Shop stehen diverse Schilder.\n\nSchilder und Dialoge:\n\n''Ohne Konservierungsstoffe!'' - ''Ich war sowieso noch nie konservativ.''\n\n''Biifiii, heute ca. 5 Minuten später'' - ''Ach ja, so ist Sie, die Deutsche Bar, \nlässt immer ein wenig auf sich warten.''\nDanach neuer Text:''heute ca. 10 Minuten später''\n\nDer Bus-Shop ist nur im ersten Akt zugegen. Danach zieht er weiter und gibt den Weg zum zweiten Akt frei. Alle Schilder sind dann abgebaut und hinter dem Schilder-Meer kommt eine Marihuana Pflanze zum Vorschein, neben der ein kleiner bekiffter Wichtel steht.', 3),
(25, 'Im Bus-Shop', 'Der Bus-Shop ist ein Fahrender Händler. Der Verkäufer zieht mit seinem Bus von Dorf zu Dorf und verkauft seine Waren. Das Verkaufsinventar besteht ausschließlich aus Zeitschriften und Schildern. Von ihm erhält man einige Unnütze Informationen zu aktuellen Ereignissen.', 3),
(26, 'Der Katzenbaum', 'Neben der Straße steht der größte Baum des Dorfes. Auf diesem Baum hat die Katze der Alten Frau es sich gemütlich gemacht. Die Alte Frau steht unten und jammert um ihre Katze.\n\nNach Lösen des Rätsels  >Die Katze im Baum<  sitzen  >Die Alte Frau<  und  >Der Alte Mann<  Hand in Hand auf der Bank.', 3),
(27, 'Das Katzenbaumhaus', 'Das Katzenbaumhaus ist die Neue Behausung der Katze der Alten Frau. Es ist das Wahre Katzenparadies. Geschaffen von einer Katze für zwei Katzen. Für sich selbst und für den geliebten. Es besteht aus Röhren in alle Richtungen, eine Kratz-Vorrichtung und einem Lagerraum mit Mausefallen. zusätzlich gibt es eine Plattform, von der aus die Katze sich dem alten Besitzer Zeigen kann um so zu tun, als traue man sich nicht herunter.', 3),
(28, 'Balkon', 'noch nicht bearbeitet', 2),
(29, 'Dachboden', 'noch nicht bearbeitet', 2),
(30, 'Garten 1', 'noch nicht bearbeitet', 2),
(31, 'Garten 2', 'noch nicht bearbeitet', 2),
(32, 'Gartenlaube', 'noch nicht bearbeitet', 2),
(33, 'Die Statue', 'noch nicht bearbeitet', 3),
(34, 'Blick durch''s Fernrohr', 'noch nicht bearbeitet', 2),
(35, 'Die Baustelle', 'noch nicht bearbeitet', 3),
(36, 'Das Wartezimmer', 'noch nicht bearbeitet', 4),
(37, 'Die Toilette', 'noch nicht bearbeitet', 4),
(38, 'Der Behandlungsraum', 'noch nicht bearbeitet', 4),
(39, 'vor dem Psycho Haus', 'noch nicht bearbeitet', 3),
(40, 'vor der Pizza', 'noch nicht bearbeitet', 3),
(41, 'Parkplatz', 'noch nicht bearbeitet', 3),
(42, 'vor Mayas Haus', 'noch nicht bearbeitet', 3),
(43, 'am See', 'noch nicht bearbeitet', 3),
(44, 'um den See', 'noch nicht bearbeitet', 3),
(45, 'Die Weggabelung', 'Der erste Screen im 2. Akt.\n\nAuf der Weggabelung steht ein Wegweiser, der in Die Richtungen ''Sicher'' und ''Gefahr'' deutet.\n\nDie Aussichten auf diese Richtungen suggerieren allerdings das genaue Gegenteil.\nDie ''Sichere'' Seite ist voller Schmutz, die Wege sind verwuchert, überall stehen Schilder, die auf Gefahr hindeuten.\nWährend auf der ''gefährlichen'' Seite alles grünt und blüht und die Sonne scheint.', 9),
(46, 'Baumtempel', 'noch nicht bearbeitet', 9),
(47, 'Flusstempel', 'noch nicht bearbeitet', 9),
(48, 'Erdtempel', 'noch nicht bearbeitet', 9),
(49, 'Lichtungstempel', 'noch nicht bearbeitet', 9);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `ui_answers`
--

CREATE TABLE IF NOT EXISTS `ui_answers` (
  `answerid` int(12) NOT NULL,
  `commentid` int(12) NOT NULL,
  PRIMARY KEY (`answerid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `ui_comments`
--

CREATE TABLE IF NOT EXISTS `ui_comments` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `userid` int(12) NOT NULL,
  `text` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `ui_feed`
--

CREATE TABLE IF NOT EXISTS `ui_feed` (
  `userid` int(11) NOT NULL,
  `site` varchar(4) NOT NULL,
  `refid` int(11) NOT NULL,
  PRIMARY KEY (`userid`,`site`,`refid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `ui_feed`
--

INSERT INTO `ui_feed` (`userid`, `site`, `refid`) VALUES
(2, 'akte', 1),
(2, 'akte', 2),
(2, 'akte', 3),
(2, 'akte', 4),
(2, 'akte', 6),
(2, 'akte', 7),
(2, 'akte', 8),
(2, 'akte', 9),
(2, 'akte', 10),
(2, 'akte', 11),
(2, 'akte', 12),
(2, 'char', 1),
(2, 'char', 2),
(2, 'char', 3),
(2, 'char', 4),
(2, 'char', 5),
(2, 'char', 6),
(2, 'char', 7),
(2, 'char', 8),
(2, 'char', 9),
(2, 'char', 16),
(2, 'char', 17),
(2, 'char', 20),
(2, 'char', 21),
(2, 'char', 22),
(2, 'char', 23),
(2, 'char', 24),
(2, 'char', 25),
(2, 'char', 26),
(2, 'char', 27),
(2, 'char', 28),
(2, 'char', 29),
(2, 'char', 30),
(2, 'char', 31),
(2, 'char', 32),
(2, 'char', 33),
(2, 'item', 11),
(2, 'item', 12),
(2, 'item', 13),
(2, 'item', 14),
(2, 'item', 15),
(2, 'item', 16),
(2, 'item', 17),
(2, 'item', 18),
(2, 'item', 19),
(2, 'item', 20),
(2, 'item', 21),
(2, 'item', 22),
(2, 'item', 23),
(2, 'item', 24),
(2, 'item', 25),
(2, 'orte', 3),
(2, 'orte', 8),
(2, 'orte', 9),
(2, 'raet', 1),
(2, 'raet', 2),
(2, 'raet', 6),
(2, 'raet', 8),
(2, 'raet', 9),
(2, 'raet', 10),
(2, 'raet', 11),
(2, 'scre', 8),
(2, 'scre', 10),
(2, 'scre', 11),
(2, 'scre', 26),
(2, 'scre', 27),
(2, 'scre', 28),
(2, 'scre', 32),
(2, 'scre', 33),
(2, 'scre', 34),
(2, 'scre', 35),
(2, 'scre', 36),
(2, 'scre', 37),
(2, 'scre', 38),
(2, 'scre', 39),
(2, 'scre', 40),
(2, 'scre', 41),
(2, 'scre', 42),
(2, 'scre', 43),
(2, 'scre', 44),
(2, 'scre', 45),
(2, 'scre', 46),
(2, 'scre', 47),
(2, 'scre', 48),
(2, 'scre', 49),
(3, 'akte', 1),
(3, 'akte', 2),
(3, 'akte', 3),
(3, 'akte', 4),
(3, 'akte', 6),
(3, 'akte', 7),
(3, 'akte', 8),
(3, 'akte', 9),
(3, 'akte', 10),
(3, 'akte', 11),
(3, 'akte', 12),
(3, 'char', 1),
(3, 'char', 2),
(3, 'char', 3),
(3, 'char', 4),
(3, 'char', 5),
(3, 'char', 6),
(3, 'char', 7),
(3, 'char', 8),
(3, 'char', 9),
(3, 'char', 16),
(3, 'char', 17),
(3, 'char', 20),
(3, 'char', 21),
(3, 'char', 22),
(3, 'char', 23),
(3, 'char', 24),
(3, 'char', 25),
(3, 'char', 26),
(3, 'char', 27),
(3, 'char', 28),
(3, 'char', 29),
(3, 'char', 30),
(3, 'char', 31),
(3, 'char', 32),
(3, 'char', 33),
(3, 'item', 11),
(3, 'item', 12),
(3, 'item', 13),
(3, 'item', 14),
(3, 'item', 15),
(3, 'item', 16),
(3, 'item', 17),
(3, 'item', 18),
(3, 'item', 19),
(3, 'item', 20),
(3, 'item', 21),
(3, 'item', 22),
(3, 'item', 23),
(3, 'item', 24),
(3, 'item', 25),
(3, 'orte', 3),
(3, 'orte', 8),
(3, 'orte', 9),
(3, 'raet', 1),
(3, 'raet', 2),
(3, 'raet', 6),
(3, 'raet', 8),
(3, 'raet', 9),
(3, 'raet', 10),
(3, 'raet', 11),
(3, 'scre', 8),
(3, 'scre', 10),
(3, 'scre', 11),
(3, 'scre', 26),
(3, 'scre', 27),
(3, 'scre', 28),
(3, 'scre', 32),
(3, 'scre', 33),
(3, 'scre', 34),
(3, 'scre', 35),
(3, 'scre', 36),
(3, 'scre', 37),
(3, 'scre', 38),
(3, 'scre', 39),
(3, 'scre', 40),
(3, 'scre', 41),
(3, 'scre', 42),
(3, 'scre', 43),
(3, 'scre', 44),
(3, 'scre', 45),
(3, 'scre', 46),
(3, 'scre', 47),
(3, 'scre', 48),
(3, 'scre', 49),
(4, 'akte', 1),
(4, 'akte', 2),
(4, 'akte', 3),
(4, 'akte', 4),
(4, 'akte', 7),
(4, 'akte', 8),
(4, 'akte', 9),
(4, 'akte', 10),
(4, 'akte', 11),
(4, 'akte', 12),
(4, 'char', 1),
(4, 'char', 3),
(4, 'char', 4),
(4, 'char', 5),
(4, 'char', 6),
(4, 'char', 7),
(4, 'char', 8),
(4, 'char', 9),
(4, 'char', 16),
(4, 'char', 17),
(4, 'char', 20),
(4, 'char', 21),
(4, 'char', 22),
(4, 'char', 23),
(4, 'char', 24),
(4, 'char', 26),
(4, 'char', 27),
(4, 'char', 28),
(4, 'char', 29),
(4, 'char', 30),
(4, 'char', 31),
(4, 'char', 32),
(4, 'char', 33),
(4, 'item', 11),
(4, 'item', 12),
(4, 'item', 13),
(4, 'item', 14),
(4, 'item', 15),
(4, 'item', 16),
(4, 'item', 17),
(4, 'item', 18),
(4, 'item', 19),
(4, 'item', 20),
(4, 'item', 21),
(4, 'item', 22),
(4, 'item', 23),
(4, 'item', 24),
(4, 'item', 25),
(4, 'orte', 3),
(4, 'orte', 8),
(4, 'orte', 9),
(4, 'raet', 1),
(4, 'raet', 2),
(4, 'raet', 6),
(4, 'raet', 8),
(4, 'raet', 9),
(4, 'raet', 10),
(4, 'raet', 11),
(4, 'scre', 8),
(4, 'scre', 10),
(4, 'scre', 11),
(4, 'scre', 26),
(4, 'scre', 27),
(4, 'scre', 28),
(4, 'scre', 32),
(4, 'scre', 33),
(4, 'scre', 34),
(4, 'scre', 35),
(4, 'scre', 36),
(4, 'scre', 37),
(4, 'scre', 38),
(4, 'scre', 39),
(4, 'scre', 40),
(4, 'scre', 41),
(4, 'scre', 42),
(4, 'scre', 43),
(4, 'scre', 44),
(4, 'scre', 45),
(4, 'scre', 46),
(4, 'scre', 47),
(4, 'scre', 48),
(4, 'scre', 49),
(5, 'akte', 2),
(5, 'akte', 3),
(5, 'akte', 4),
(5, 'akte', 8),
(5, 'akte', 9),
(5, 'akte', 11),
(5, 'akte', 12),
(5, 'char', 4),
(5, 'char', 5),
(5, 'char', 7),
(5, 'char', 8),
(5, 'char', 17),
(5, 'char', 29),
(5, 'char', 30),
(5, 'char', 31),
(5, 'char', 32),
(5, 'char', 33),
(5, 'item', 14),
(5, 'item', 15),
(5, 'item', 16),
(5, 'item', 17),
(5, 'item', 18),
(5, 'item', 19),
(5, 'item', 20),
(5, 'item', 21),
(5, 'item', 22),
(5, 'item', 23),
(5, 'item', 24),
(5, 'item', 25),
(5, 'orte', 3),
(5, 'orte', 8),
(5, 'orte', 9),
(5, 'raet', 11),
(5, 'scre', 45),
(5, 'scre', 46),
(5, 'scre', 47),
(5, 'scre', 48),
(5, 'scre', 49),
(6, 'akte', 1),
(6, 'akte', 2),
(6, 'akte', 3),
(6, 'akte', 4),
(6, 'akte', 6),
(6, 'akte', 7),
(6, 'akte', 8),
(6, 'akte', 9),
(6, 'akte', 10),
(6, 'akte', 11),
(6, 'akte', 12),
(6, 'char', 1),
(6, 'char', 2),
(6, 'char', 3),
(6, 'char', 4),
(6, 'char', 5),
(6, 'char', 6),
(6, 'char', 7),
(6, 'char', 8),
(6, 'char', 9),
(6, 'char', 16),
(6, 'char', 17),
(6, 'char', 20),
(6, 'char', 21),
(6, 'char', 22),
(6, 'char', 23),
(6, 'char', 24),
(6, 'char', 25),
(6, 'char', 26),
(6, 'char', 27),
(6, 'char', 28),
(6, 'char', 29),
(6, 'char', 30),
(6, 'char', 31),
(6, 'char', 32),
(6, 'char', 33),
(6, 'item', 11),
(6, 'item', 12),
(6, 'item', 13),
(6, 'item', 14),
(6, 'item', 15),
(6, 'item', 16),
(6, 'item', 17),
(6, 'item', 18),
(6, 'item', 19),
(6, 'item', 20),
(6, 'item', 21),
(6, 'item', 22),
(6, 'item', 23),
(6, 'item', 24),
(6, 'item', 25),
(6, 'orte', 3),
(6, 'orte', 8),
(6, 'orte', 9),
(6, 'raet', 1),
(6, 'raet', 2),
(6, 'raet', 6),
(6, 'raet', 8),
(6, 'raet', 9),
(6, 'raet', 10),
(6, 'raet', 11),
(6, 'scre', 8),
(6, 'scre', 10),
(6, 'scre', 11),
(6, 'scre', 26),
(6, 'scre', 27),
(6, 'scre', 28),
(6, 'scre', 32),
(6, 'scre', 33),
(6, 'scre', 34),
(6, 'scre', 35),
(6, 'scre', 36),
(6, 'scre', 37),
(6, 'scre', 38),
(6, 'scre', 39),
(6, 'scre', 40),
(6, 'scre', 41),
(6, 'scre', 42),
(6, 'scre', 43),
(6, 'scre', 44),
(6, 'scre', 45),
(6, 'scre', 46),
(6, 'scre', 47),
(6, 'scre', 48),
(6, 'scre', 49),
(7, 'akte', 3),
(7, 'akte', 4),
(7, 'akte', 11),
(7, 'akte', 12),
(7, 'char', 8),
(7, 'char', 17),
(7, 'char', 29),
(7, 'char', 30),
(7, 'char', 31),
(7, 'char', 32),
(7, 'char', 33),
(7, 'item', 20),
(7, 'item', 21),
(7, 'item', 22),
(7, 'item', 23),
(7, 'item', 24),
(7, 'item', 25),
(7, 'orte', 3),
(7, 'orte', 9),
(7, 'scre', 45),
(7, 'scre', 46),
(7, 'scre', 47),
(7, 'scre', 48),
(7, 'scre', 49);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `ui_images`
--

CREATE TABLE IF NOT EXISTS `ui_images` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `path` varchar(32) NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=181 ;

--
-- Daten für Tabelle `ui_images`
--

INSERT INTO `ui_images` (`id`, `path`, `description`) VALUES
(118, '118.jpg', ''),
(117, '117.jpg', ''),
(116, '116.jpg', ''),
(115, '115.jpg', ''),
(114, '114.png', ''),
(109, '109.jpg', ''),
(108, '108.jpg', ''),
(107, '107.jpg', ''),
(102, '102.jpg', ''),
(101, '101.jpg', ''),
(100, '100.jpg', ''),
(99, '99.jpg', ''),
(98, '98.jpg', ''),
(97, '97.jpg', ''),
(96, '96.jpg', ''),
(95, '95.jpg', ''),
(94, '94.jpg', ''),
(93, '93.jpg', ''),
(92, '92.jpg', ''),
(91, '91.jpg', ''),
(90, '90.jpg', ''),
(89, '89.jpg', ''),
(88, '88.jpg', ''),
(87, '87.jpg', ''),
(86, '86.jpg', ''),
(85, '1.jpg', ''),
(119, '119.jpg', ''),
(120, '120.jpg', ''),
(121, '121.jpg', ''),
(122, '122.jpg', ''),
(123, '123.jpg', ''),
(124, '124.jpg', ''),
(125, '125.jpg', ''),
(126, '126.jpg', ''),
(127, '127.jpg', ''),
(128, '128.jpg', ''),
(129, '129.jpg', ''),
(130, '130.jpg', ''),
(131, '131.jpg', ''),
(132, '132.jpg', ''),
(133, '133.jpg', ''),
(134, '134.jpg', ''),
(135, '135.jpg', ''),
(136, '136.jpg', ''),
(137, '137.jpg', ''),
(138, '138.jpg', ''),
(139, '139.jpg', ''),
(140, '140.jpg', ''),
(141, '141.jpg', ''),
(142, '142.jpg', ''),
(143, '143.jpg', ''),
(144, '144.jpg', ''),
(145, '145.jpg', ''),
(146, '146.jpg', ''),
(147, '147.jpg', ''),
(148, '148.jpg', ''),
(149, '149.jpg', ''),
(150, '150.jpg', ''),
(151, '151.jpg', ''),
(152, '152.jpg', ''),
(153, '153.jpg', ''),
(154, '154.jpg', ''),
(155, '155.jpg', ''),
(171, '171.jpg', ''),
(170, '170.jpg', ''),
(169, '169.jpg', ''),
(168, '168.jpg', ''),
(167, '167.jpg', ''),
(166, '166.jpg', ''),
(165, '165.jpg', ''),
(172, '172.jpg', ''),
(173, '173.jpg', ''),
(174, '174.jpg', ''),
(175, '175.jpg', ''),
(176, '176.jpg', ''),
(177, '177.jpg', ''),
(178, '178.jpg', ''),
(179, '179.jpg', ''),
(180, '180.png', '');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `ui_images_articles`
--

CREATE TABLE IF NOT EXISTS `ui_images_articles` (
  `imageid` int(11) NOT NULL,
  `site` varchar(4) NOT NULL,
  `refid` int(11) NOT NULL,
  PRIMARY KEY (`imageid`,`site`,`refid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `ui_images_articles`
--

INSERT INTO `ui_images_articles` (`imageid`, `site`, `refid`) VALUES
(85, 'akte', 7),
(86, 'akte', 7),
(86, 'char', 14),
(87, 'akte', 7),
(87, 'char', 14),
(88, 'akte', 7),
(88, 'char', 16),
(88, 'scre', 35),
(89, 'akte', 7),
(89, 'char', 16),
(89, 'scre', 35),
(90, 'akte', 7),
(90, 'char', 16),
(91, 'akte', 7),
(91, 'char', 16),
(92, 'akte', 7),
(92, 'char', 16),
(93, 'akte', 7),
(93, 'char', 12),
(94, 'akte', 7),
(94, 'char', 12),
(95, 'akte', 7),
(95, 'char', 16),
(96, 'akte', 7),
(96, 'char', 18),
(97, 'akte', 7),
(97, 'char', 18),
(98, 'akte', 7),
(98, 'char', 10),
(99, 'akte', 7),
(99, 'char', 17),
(100, 'akte', 7),
(100, 'char', 17),
(101, 'akte', 7),
(101, 'char', 11),
(102, 'akte', 7),
(102, 'char', 16),
(107, 'akte', 7),
(107, 'scre', 13),
(108, 'akte', 7),
(108, 'scre', 14),
(109, 'akte', 7),
(109, 'scre', 12),
(114, 'akte', 7),
(115, 'akte', 7),
(115, 'scre', 8),
(116, 'akte', 7),
(116, 'scre', 7),
(117, 'akte', 7),
(117, 'scre', 9),
(118, 'akte', 7),
(119, 'akte', 7),
(120, 'akte', 7),
(121, 'akte', 7),
(121, 'scre', 10),
(122, 'akte', 7),
(122, 'scre', 6),
(123, 'akte', 7),
(123, 'scre', 11),
(124, 'akte', 7),
(124, 'scre', 28),
(125, 'akte', 7),
(125, 'scre', 29),
(126, 'akte', 7),
(126, 'scre', 29),
(127, 'akte', 7),
(127, 'scre', 30),
(128, 'akte', 7),
(128, 'scre', 31),
(129, 'akte', 7),
(129, 'raet', 1),
(129, 'scre', 4),
(130, 'akte', 7),
(130, 'scre', 1),
(131, 'akte', 7),
(131, 'scre', 3),
(132, 'akte', 7),
(132, 'scre', 2),
(133, 'akte', 7),
(133, 'char', 13),
(134, 'akte', 7),
(134, 'char', 24),
(135, 'akte', 7),
(135, 'scre', 40),
(136, 'akte', 7),
(136, 'scre', 15),
(137, 'akte', 7),
(137, 'scre', 42),
(138, 'akte', 7),
(138, 'scre', 17),
(139, 'akte', 7),
(139, 'scre', 35),
(140, 'akte', 7),
(140, 'scre', 43),
(141, 'akte', 7),
(141, 'scre', 39),
(142, 'akte', 7),
(142, 'scre', 24),
(143, 'akte', 7),
(143, 'scre', 44),
(144, 'akte', 7),
(145, 'akte', 7),
(145, 'scre', 21),
(146, 'akte', 7),
(146, 'scre', 20),
(147, 'akte', 7),
(147, 'scre', 19),
(148, 'akte', 7),
(148, 'scre', 18),
(149, 'akte', 7),
(149, 'scre', 5),
(150, 'akte', 7),
(150, 'scre', 41),
(151, 'akte', 7),
(151, 'scre', 25),
(152, 'akte', 7),
(152, 'scre', 26),
(153, 'akte', 7),
(153, 'scre', 36),
(154, 'akte', 7),
(154, 'scre', 38),
(155, 'akte', 7),
(155, 'scre', 35),
(165, 'akte', 7),
(165, 'scre', 32),
(166, 'akte', 7),
(166, 'scre', 34),
(167, 'akte', 7),
(167, 'scre', 27),
(168, 'akte', 7),
(168, 'scre', 33),
(169, 'akte', 7),
(169, 'char', 4),
(170, 'akte', 7),
(170, 'char', 5),
(171, 'akte', 7),
(171, 'char', 22),
(171, 'char', 23),
(172, 'akte', 7),
(172, 'char', 16),
(172, 'scre', 34),
(173, 'akte', 7),
(173, 'scre', 37),
(174, 'akte', 7),
(174, 'char', 25),
(175, 'akte', 7),
(175, 'char', 25),
(176, 'akte', 7),
(176, 'char', 3),
(177, 'akte', 7),
(177, 'char', 7),
(178, 'akte', 7),
(178, 'char', 7),
(179, 'akte', 7),
(179, 'char', 3),
(180, 'akte', 7),
(180, 'scre', 26);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `ui_user`
--

CREATE TABLE IF NOT EXISTS `ui_user` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `password` varchar(32) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Daten für Tabelle `ui_user`
--

INSERT INTO `ui_user` (`id`, `name`, `password`) VALUES
(1, 'Manu', 'fd30a04543a8024e01620e12b0a01187'),
(2, 'Christian', 'f0a1fa7abc0f191b7538a4f9df8ded9b'),
(3, 'Valentin', 'd4b9fa323122753292161c3d016c122a'),
(4, 'Anna', 'eb09d5e396183f4b71c3c798158f7c07'),
(5, 'Chrisch', '13c4629d67740eadbaaf0bb68bfbe9c8'),
(6, 'Seb', 'c66ed2847ef078be46d2b8fee9a16710'),
(7, 'mihail', '6b7addb310328e6ef409f202c64c4c89');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
