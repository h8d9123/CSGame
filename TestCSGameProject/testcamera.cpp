#include "stdafx.h"
#include "CppUnitTest.h"

#include <CSCamera.h>
#include <d3d9.h>
#include<d3dx9math.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cs;
namespace TestCSGameProject
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(test_setPos)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			D3DXVECTOR3 v0(1.0,2.0,3.0);
			camera.SetPos(v0);
			D3DXVECTOR3 v = camera.GetPos();
			for (int i = 0 ; i < 3; i++)
				Assert::AreEqual(v[i], v0[i]);
			
		}

		TEST_METHOD(test_setLookVec)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			D3DXVECTOR3 v0(1.0, 2.0, 3.0);
			camera.SetLookVec(v0);
			D3DXVECTOR3 v = camera.GetLookVec();
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(v[i], v0[i]);

		}

		TEST_METHOD(test_setUpVec)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			D3DXVECTOR3 v0(1.0, 2.0, 3.0);
			camera.SetUpVec(v0);
			D3DXVECTOR3 v = camera.GetUpVec();
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(v[i], v0[i]);

		}

		TEST_METHOD(test_setRightVec)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			D3DXVECTOR3 v0(1.0, 2.0, 3.0);
			camera.SetRightVec(v0);
			D3DXVECTOR3 v = camera.GetRightVec();
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(v[i], v0[i]);
		}
		TEST_METHOD(test_GetViewMarix)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			//camera.Pitch();
			D3DXMATRIXA16 m0;
			camera.GetViewMatirx(&m0);


		}

		TEST_METHOD(test_Pitch)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			camera.Pitch(3.141/2.0);

		}
		TEST_METHOD(test_Yaw)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			camera.Yaw(3.141/2.0);

		}

		TEST_METHOD(test_Roll)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			camera.Yaw(3.141/2.0);

		}
		TEST_METHOD(test_Strafe)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			camera.Strafe(1.0);

		}
		TEST_METHOD(test_Fly)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			camera.Fly(3.0);

		}
		TEST_METHOD(test_Walk)
		{
			// TODO: 在此输入测试代码
			CSCamera camera(CSCamera::CAMERATYPE::LANDCAMERA);
			camera.Walk(5.0);

		}
	};

}