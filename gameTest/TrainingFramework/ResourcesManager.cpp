#include "stdafx.h"
#include "ResourcesManager.h"

ResourcesManager* ResourcesManager::ms_pInstance = NULL;

void ResourcesManager::init()
{
	FILE* f_RM;
	f_RM = fopen("../Resources/Managers/RM.txt", "r");
	if (f_RM != NULL) {
		this->ReadFile(f_RM);
	}
	fclose(f_RM);
}

void ResourcesManager::clearMem()
{
	for (int i = 0; i < m_Models.size(); i++) {
		delete m_Models[i];
	}
	for (int i = 0; i < m_Textures.size(); i++) {
		delete m_Textures[i];
	}
	for (int i = 0; i < m_Shaders.size(); i++) {
		delete m_Shaders[i];
	}
	for (int i = 0; i < m_BackgroundTextures.size(); i++) {
		delete m_BackgroundTextures[i];
	}
	for (int i = 0; i < m_TerrainTextures.size(); i++) {
		delete m_TerrainTextures[i];
	}
	for (int i = 0; i < m_Animations.size(); i++) {
		delete m_Animations[i];
	}
	for (int i = 0; i < m_DumpAnim.size(); i++) {
		delete m_DumpAnim[i];
	}
}

void ResourcesManager::ReadFile(FILE * f_RM)
{
	//Animations
	int numAnimations;
	fscanf_s(f_RM, "#Animations: %d\n", &numAnimations);
	for (register int i = 0; i < numAnimations; i++) {
		int ID;
		char File[250]; float speed; int fire;
		fscanf_s(f_RM, "ID %d\n", &ID);
		fscanf_s(f_RM, "FILE %s\n", File, _countof(File));
		fscanf_s(f_RM, "SPEED %f %d\n", &speed, &fire);
		Animation* anim = new Animation(File);
		anim->setAnimationSpeed(speed);
		anim->setID(ID);
		anim->setFire(fire);
		m_Animations.push_back(anim);
	}

	//Textures
	int numOfTextures;
	fscanf_s(f_RM, "#2D Textures: %d\n", &numOfTextures);
	for (register int i = 0; i < numOfTextures; i++) {
		int ID;
		char File[250];
		fscanf_s(f_RM, "ID %d\n", &ID);
		fscanf_s(f_RM, "FILE %s\n", File, _countof(File));

		Texture* texture = new Texture(ID, File);
		texture->Init();
		m_Textures.push_back(texture);
	}

	//Background
	int numOfBackground;
	fscanf_s(f_RM, "#Background: %d\n", &numOfBackground);
	for (register int i = 0; i < numOfBackground; i++) {
		int ID;
		char File[250];
		fscanf_s(f_RM, "ID %d\n", &ID);
		fscanf_s(f_RM, "FILE %s\n", File, _countof(File));

		Texture* texture = new Texture(ID, File);
		texture->Init();
		m_BackgroundTextures.push_back(texture);
	}

	//Tile
	int numOfTile;
	fscanf_s(f_RM, "#Tile: %d\n", &numOfTile);
	for (register int i = 0; i < numOfTile; i++) {
		int ID;
		char File[250];
		fscanf_s(f_RM, "ID %d\n", &ID);
		fscanf_s(f_RM, "FILE %s\n", File, _countof(File));

		Texture* texture = new Texture(ID, File);
		texture->Init();
		m_TerrainTextures.push_back(texture);
	}

	//Shaders
	int numOfShaders;
	fscanf_s(f_RM, "#Shaders: %d\n", &numOfShaders);
	for (register int i = 0; i < numOfShaders; i++) {
		int ID, states, depth_test = 0, cull_face = 0, blend = 0;
		char FileVS[250], FileFS[250];
		fscanf_s(f_RM, "ID %d\n", &ID);
		fscanf_s(f_RM, "VS %s\n", FileVS, _countof(FileVS));
		fscanf_s(f_RM, "FS %s\n", FileFS, _countof(FileFS));
		fscanf_s(f_RM, "STATES %d\n", &states);
		if (states > 0) {
			fscanf_s(f_RM, "GL_DEPTH_TEST %d\n", &depth_test);
			states--;
		}
		if (states > 0) {
			fscanf_s(f_RM, "GL_CULL_FACE %d\n", &cull_face);
			states--;
		}
		if (states > 0) {
			fscanf_s(f_RM, "GL_BLEND %d\n", &blend);
			states--;
		}

		Shaders* shader = new Shaders(ID, FileVS, FileFS, depth_test, cull_face, blend);
		shader->Init();
		m_Shaders.push_back(shader);
	}

}

Model * ResourcesManager::GetModelAtID(int ID)
{
	for (register int i = 0; i < m_Models.size(); i++) {
		if (m_Models[i]->GetID() == ID) {
			return m_Models[i];
		}
	}
	return NULL;
}

Animation * ResourcesManager::GetAnimationAtID(int ID)
{
	for (int i = 0; i < m_Animations.size(); i++) {
		if (m_Animations[i]->GetID() == ID) {
			return m_Animations[i];
		}
	}
	return NULL;
}

Texture * ResourcesManager::GetTextureAtID(int ID)
{
	for (register int i = 0; i < m_Textures.size(); i++) {
		if (m_Textures[i]->GetID() == ID) {
			return m_Textures[i];
		}
	}
	return NULL;
}

Shaders * ResourcesManager::GetShaderAtID(int ID)
{
	for (register int i = 0; i < m_Shaders.size(); i++) {
		if (m_Shaders[i]->GetID() == ID) {
			return m_Shaders[i];
		}
	}
	return NULL;
}

Texture * ResourcesManager::GetBackgroundAtID(int ID)
{
	for (register int i = 0; i < m_BackgroundTextures.size(); i++) {
		if (m_BackgroundTextures[i]->GetID() == ID) {
			return m_BackgroundTextures[i];
		}
	}
	return NULL;
}

Texture * ResourcesManager::GetTerrainAtID(int ID)
{
	for (register int i = 0; i < m_TerrainTextures.size(); i++) {
		if (m_TerrainTextures[i]->GetID() == ID) {
			return m_TerrainTextures[i];
		}
	}
	return NULL;
}

void ResourcesManager::addDumpAnim(Animation * anim)
{
	m_DumpAnim.push_back(anim);
}
