#pragma once
#include<vector>
#include<iterator>
#include<map>
#include<cassert>
/*
1-p65 1.6.3
*/
namespace cs 
{

	typedef LPDIRECTDRAWSURFACE7 OsHandle;
	struct tagTexture{};
	typedef Handle<tagTexture> HTexture;

	class TextureMgr
	{
		struct Texture
		{
			typedef std::vector<OsHandle>HandleVec;
			std::string m_Name;
			unsigned int m_Width;
			unsigned int m_Height;
			HandleVec m_Handles;


			OsHandle GetOsHandle(unsigned int mip) const
			{
				assert(mip < m_Handles.size());
				return m_Handles[mip];
			}

			bool Load(const std::string& name);
			void UnLoad(void);
		};

		typedef HandleMgr<Texture, HTexture> HTextureMgr;

		struct isstring_less
		{
			bool operator()(const std::string& l, const std::string& r)const
			{
				return(::stricmp(l.c_str(), r.c_str()) < 0);
			}
		};
		typedef std::map	<std::string, HTexture, isstring_less> NameIndex;
		typedef std::pair<NameIndex::iterator, bool> NameIndexInsertRC;
	private:
		HTextureMgr m_Textures;
		NameIndex m_NameIndex;
	public:
		TextureMgr(void) {};
		~TextureMgr(void);

		//材质管理
		HTexture GetTexture(const str* name);
		void Delete(HTexture htex);

		//材质查询

		const std::string& GetName(HTexture htex)const;
		{
			return (m_Textures.Dereference(htex)->m_name);
		}
		int GetWidth(HTexture htex)const
		{
			return (m_Textures.Dereference(htex)->m_width);
		}

		int GetHeight(HTexture htex)const
		{
			return (m_Textures.Dereference(htex)->m_Height);
		}
		//OSHandle 和HTexture？
		OsHandle GetTexture(HTexture htex, unsigned int mip = 0)const
		{
			return (m_Textures.Dereference(htex)->GetOSHandle(mip)
		}
	};

	TextureMgr::~TextureMgr(void)
	{
		NameIndex::iterator i, begin = m_NameIndex.begin(),
			end = m_NameIndex.end();
		for (i = begin; i != end; i++)
		{
			m_Textures.Dereference(i->second)->UnLoad();
		}
	}

	HTexture TextureMgr::GetTexture(const char* name)
	{
		NameIndexInsertRc rc = 
			NameIndex.insert(std::make_pair(name, HTexture()));
		if (rc.second)
		{
			Texture* tex = m_Textures.Acquire(rc.first->second);
			if (!tex->Load(rc.first->first))
			{
				DeleteTexture(rc.first->second);
				rc.first->second = HTexture();
			}
		}
		return(rc.first->second);
	}

	void TextureMgr::DeLeteTexture(HTexture htex)
	{
		Texture*tex = m_Textures.Derefrence(htex);
		if (tex != 0)
		{
			m_NameIndex.erase(m_NameIndex.find(tex->m_Name));
			tex->UnLoad();
			m_Textures.Release(htex);
		}
	}

	bool TextureMgr::Texture::Load(const std::string& name)
	{
		m_Name = name;
		//载入资源,失败返回false
		//TODO
		return true;
	}

	void Texture::Texture::UnLoad(void)
	{
		m_Name.erase();
		//释放surface
		//	TODO
		m_Handles.clear();
	}
}

