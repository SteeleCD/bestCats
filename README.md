bestCats
========

Pick most appropriate cat for adopter based on database

Enter user references (what characteristics adopter wants in a cat) into userPrefs.txt. These are tertiary string variables that can take values "yes", "no", or "maybe".

Enter the cat database (what characteristics each cat has) into database.txt. These are binary string variables that can take values "true" or "false".

The program then ranks the cats by how suitable they are for the user. All "yes" requests of the user must be "true" for the cat. The remaining cats are then ordered by the number of "maybe" requests of the user that are "true" for the cats.
