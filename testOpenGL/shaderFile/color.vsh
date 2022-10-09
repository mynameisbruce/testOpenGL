#version 330 core
layout (location = 0) in vec3 aPos;   // 位置变量的属性位置值为 0
layout (location = 1) in vec3 aNormal; // 法向量
layout (location = 2) in vec2 aTexCoords; // 法向量

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// 输出法向量
out vec3 Normal;
// 输出片段位置
out vec3 FragPos;
// 输出纹理数据
out vec2 TexCoords;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0); // vec4(aPos, 1.0); //
    FragPos = vec3(model * vec4(aPos, 1.0)); // 使用模型视图矩阵获取世界坐标
    Normal = mat3(transpose(inverse(model))) * aNormal;   // 法向量赋值
    TexCoords = aTexCoords; // 纹理数据
}
