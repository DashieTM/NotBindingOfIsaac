#include <vector>
#include <memory>
#include <map>
#include "Entity.h"

class EntityManager {
public:
    enum EType {ENEMY, PLAYER, NPC, NDEF};    
    typedef std::vector<std::shared_ptr<Entity>> EntityVec;
    typedef std::map<EType,EntityVec> EntityMap;

protected:
    EntityVec EntityList;
    EntityMap EntityTypeList;
    int entityAmount;


public:
    EntityManager();
    ~EntityManager();

    EntityVec& getEntityVec();
    EntityVec& getTypeEntityVec(EType tag);

    std::shared_ptr<Entity> createEntity(EType tag);

    void update();
    void collision();



};