#include "EntityManger.h"

EntityManager::EntityManager() {};
EntityManager::~EntityManager() {};

EntityManager::EntityVec& EntityManager::getEntityVec() {
    return EntityList;
}

EntityManager::EntityVec& EntityManager::getTypeEntityVec(EType tag) {
    switch(tag) {
        case ENEMY: return EntityTypeList[ENEMY];
        case PLAYER: return EntityTypeList[PLAYER];
        case NPC: return EntityTypeList[NPC];
        default: return EntityList;
    };
}

std::shared_ptr<Entity> EntityManager::createEntity(EType tag) {
    EntityList.push_back(Entity());
    EntityTypeList[tag].push_back(Entity());
}

void EntityManager::collision() {
   
}