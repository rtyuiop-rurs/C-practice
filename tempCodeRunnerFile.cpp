  if (player.getHealth() <= 0) {
        std::cout << "\nGAME OVER! You have been defeated.\n";
    } else if (MonsterPool.empty()) {
        std::cout << "\nCONGRATULATIONS! You cleared all monsters!\n";
    }
    
    return 0;