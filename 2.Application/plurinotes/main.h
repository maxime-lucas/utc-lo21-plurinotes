#ifndef MAIN
#define MAIN

typedef enum TaskStatus { PENDING, PROGRESS, FINISHED } TaskStatus;
typedef enum TypeMultimedia { PICTURE, AUDIO, VIDEO } TypeMultimedia;

#define NBMAX 100

#include <ctime>
#include <string>

#include "models/datetime.h"
#include "models/notesexception.h"
#include "models/p_notes.h"
#include "models/p_relations.h"
#include "models/p_versions.h"

#endif // MAIN

