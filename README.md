# **SHOOT_THEM_UP**

---

## **1. Informations Générales**

**Titre** : Project Noël.  
**Genre** : Shoot'em Up.
**Style Visuel** : Pixel Art (particules, explosions dynamiques).  
**Plateforme(s)** : PC .  
**Public cible** : Amateurs de jeux d’arcade et de défis rapides, âgés de 8 ans et plus.  
**Résumé** :  Après une invasion extraterrestre. La Terre decide alors d'envahir la planète ennemis Zenirox.

---

## **2. Concept de Base**

- **Gameplay principal** : Le joueur contrôle un vaisseau spatial, détruit des vagues d’ennemis et évite des projectiles et des obstacle pour progresser dans les niveaux.  
- **Objectifs** : Détruire les vagues d'ennemis pour pouvoir tuer le Boss de la planète Zenirox.
  - Court terme : Survivre et accumuler des  en détruisant les ennemis.
  - Long terme : Compléter les niveaux, vaincre les boss et sauver la planète.  
- **Déroulement** : Le jeu est divisé en plusieurs niveaux avec une difficulté croissante, chacun se terminant par un combat de boss unique. Pour terminer le jeu il faut donc tué le Boss du dernier niveau. 
- **Style de progression** : Défilement vertical automatique, avec des phases de répit pour récupérer des power-ups et réorganiser ses stratégies entre chaque niveau.

---

## **3. Méchaniques de Jeu**

### **3.1. Contrôle du joueur**
- **Déplacement** : Mouvement en 2 des touches directionnelles (clavier).  
- **Tir principal** : Tir automatique en maintenant en faisant un clique gauche sur la souris .  
- **Tir secondaire** : Attaque spéciale, dépendant des power-ups collectés.  
- **Obstacles** : Présence d'obstacles apportants des malus ou infligeants des dégâts au joueur .

### **3.2. Système de Scoring**
- **Score** : Une piece est equivaut à un poitnt de score pour obtenir des pièce il faut donc tué des ennemis.
- **Multiplicateurs** : Augmentez vos points en détruisant des ennemis et en ramassant des bonus.
- **Diviseur** : Diminuez vos points en touchant un obstacle ou en touchant un malus .
- **Shop** : Possibilité d'acheter des skins avec le score et/ou l'argent réel
  
### **3.3. Power-ups**
1. **Boost d'attaque**:  
   - Augmente les dégats
   - Augmente la vitesse de tir    
2. **Boosts défensifs** :  
   - Bouclier temporaire (absorbe un coup).  
   - Ralentissement des projectiles ennemis.
   - Dégâts des enemis divisé par 2  
3. **Économies** :  
   - Collecte de pièce pour acheter des skins, des sons et des bonus permanants entre les niveaux.  

### **3.4. Difficulté**
- **Modes de jeu** :  
   - Débutant : Parfait pour les nouveaux joueurs.  
   - Standard : Plus d’ennemis, tirs plus rapides.  
   - Hardcore : Tirs très complexes, erreurs non pardonnées (Enemis font plus de dégat, pas de bunus et pas de regen).

---

## **4. Conception des Ennemis**

### **4.1. Types d’ennemis**
1. **Basique** :  
   - Faible santé, tirent lentement, zero mouvement (nombreux).  
   - Exemple : vaisseau alien de reconnaissance.  
2. **Intermédiaire** :  
   - Mouvements LENT Forte santé , tirs lent.  
   - Exemple : Vaisseaux tank alien.  
3. **Avancé** :  
   - Déplacement rapide, santé normal, tirs rapides.  
   - Exemple : Vaisseau d'attaque.  

### **4.2. Boss**
Chaque niveau se termine par un boss avec des mécaniques uniques :
- **Niveau 1 : Sentinel**  
   -  principale : Mitraillette avec beaucoup de dégâts.
- **Niveau 2 : Trespasser**  
   -  principale : déplacement rapide
   - Pattern :
- **Niveau 3 : Scunner**
   -  principale : Bouclier
   - Pattern :
- **Niveau 4 : Reckoner**
   -  principale : combinaison de tous les boss précédant, amplifié avec malus qui lui rendent de la vie
---

## **5. Progression et Structure**

### **5.1. Niveaux**
1. **Niveau 1** : Haute atmosphère terrestre.  
   - Thème : Débris spatiaux, satellites détruits.  
   - Introduction aux ennemis de niveau 1
   - Ennemi : Boss 1.
     
2. **Niveau 2** : Espace.  
   - Thème : Astéroïdes destructibles et passages étroits.  
   - Introduction aux ennemis de niveau 2.
   - Ennemi : Boss 2.
     
3. **Niveau 3** : Système solaire ennemi.  
   - Thème : Structures mécaniques et machines géantes.  
   - Introduction aux ennemis de niveau 3.
   - Ennemi : Boss 3.

4. **Niveau 4** : Haute atmosphère planète ennemie.  
   - Thème : Structures mécaniques et machines géantes.  
   - Ennemi : Big Boss  

### **5.2. Rythme**
-Augmentation du nombre d'ennemis pour chaque palier  

---

## **6. Direction Artistique**

### **6.1. Style Visuel**
- Pixel art rétro combiné avec des effets modernes (glow, particules).  
- Palette de couleurs évoluant selon les niveaux :  
  - Niveau 1 : Tons Terrestre (bleu, vert).  
  - Niveau 2 : Tons spatiaux (bleu).  
  - Niveau 3 : Atmosphère extraterrestre(violet, bleu, rouge).
  - Niveaux 4 : Planète extraterrestre (rose, violet, vert).  

### **6.2. Interface utilisateur**

- **HUD** :  
   - Score en haut à gauche.  
   - Barre de vie du joueur en bas à gauche.  
   - Indicateurs de power-ups et bombes en bas à droite.  

---

## **7. Direction Audio**

### **7.1. Musique**
- Rythmes électroniques rapides pour les phases d’action.  
- Musique plus lourde et dramatique pour les combats de boss.  

### **7.2. Effets sonores**
- Sons distincts pour les tirs, les explosions, et les power-ups.  
- Signal audio pour les attaques spéciales des boss ou les situations dangereuses.  

---

## **8. Systèmes et Outils**

### **8.1. Moteur de Jeu**
- **SFML** 

### **8.2. Logiciels Recommandés**
- Pixel art : **Aseprite** pour les sprites et animations.  
- Audio : **Bfxr** pour les effets sonores, **Ableton Live** pour la musique.  

---

## **9. Monétisation**
1. **Modèle principal** : Jeu premium avec achat unique.  
2. **Contenu additionnel** (DLC) :  
   - Niveaux supplémentaires avec de nouveaux ennemis et boss.  
   - Packs de skins pour le vaisseau.  
