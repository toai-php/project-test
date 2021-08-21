#pragma once
#include <vector>
#include "Object.h"
#include "Animation.h"
class ResourcesManager 
{
private:
	static ResourcesManager* ms_pInstance;
	std::vector<Model*> m_Models;
	std::vector<Texture*> m_Textures;
	std::vector<Shaders*> m_Shaders;
	std::vector<Animation*> m_Animations;
	std::vector<Texture*> m_TerrainTextures;
	std::vector<Texture*> m_BackgroundTextures;
	std::vector<Animation*> m_DumpAnim;
public:
	static ResourcesManager* getInstance() {
		if (ms_pInstance == NULL) {
			ms_pInstance = new ResourcesManager;
		}
		return ms_pInstance;
	}
	void init();
	void clearMem();
	void ReadFile(FILE* f_RM);
	Model* GetModelAtID(int ID);
	Animation* GetAnimationAtID(int ID);
	Texture* GetTextureAtID(int ID);
	Shaders* GetShaderAtID(int ID);
	Texture* GetBackgroundAtID(int ID);
	Texture* GetTerrainAtID(int ID);
	void addDumpAnim(Animation * anim);
};

