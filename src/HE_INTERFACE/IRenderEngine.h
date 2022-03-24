#pragma once

enum class RenderGroup;
enum class RenderType;
class IRenderManager;
class IRenderEngine
{
public:
	IRenderEngine() { }
	virtual ~IRenderEngine() { }

public:
	virtual void InitScene() = 0;
	virtual void InitializeData() = 0;
	virtual void DisableRender(RenderGroup render_group) = 0;
	virtual void EnableOnlyAtGroup(RenderType render_type) = 0;

	virtual void OnDraw() = 0;

};