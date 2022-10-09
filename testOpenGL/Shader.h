//
//  Shader.hpp
//  testOpenGL
//
//  Created by 林添贵 on 2021/8/30.
//

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Shader
{
public:
    // 程序ID
    unsigned int ID;
    
    // 构造器读取并构建着色器
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    // 使用/激活程序
    void use();
    // uniform工具函数
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec3(const std::string &name, float r, float g, float b) const;
    void setVec3(const std::string &name, glm::vec3 vector) const;
    void setMat4(const std::string &name, glm::mat4 matrix) const;
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif /* SHADER_H */
