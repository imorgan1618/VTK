vtk_add_test_cxx(${vtk-module}CxxTests tests
  TestAppleBug.cxx
  TestBlurAndSobelPasses.cxx
  TestCoincident.cxx
  TestCubeMap.cxx
  TestDepthOfFieldPass.cxx
  TestDepthPeelingPass.cxx
  TestEDLPass.cxx
  TestGaussianBlurPass.cxx
  TestLightingMapLuminancePass.cxx
  TestLightingMapNormalsPass.cxx
  TestPointFillPass.cxx
  TestPointGaussianMapper.cxx
  TestPointGaussianMapperOpacity.cxx
  TestRemoveActorNonCurrentContext.cxx
  TestRenderToImage.cxx
  TestSSAAPass.cxx
  TestSetZBuffer.cxx
  TestShadowMapBakerPass.cxx
  TestShadowMapPass.cxx
  TestSobelGradientMagnitudePass.cxx
  TestUserShader.cxx
  TestUserShader2.cxx
  TestVBOPLYMapper.cxx
  TestVBOPointsLines.cxx
  TestValuePass.cxx
  TestValuePass2.cxx
  )

vtk_test_cxx_executable(${vtk-module}CxxTests tests RENDERING_FACTORY)
