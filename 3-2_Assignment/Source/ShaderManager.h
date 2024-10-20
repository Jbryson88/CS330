
#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <string>

class ShaderManager {
public:
    ShaderManager();
    ~ShaderManager();
    
    void LoadShaders(const char* vertexPath, const char* fragmentPath);
    void use();
    
    // Utility functions to set shader uniform variables
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMat4Value(const std::string &name, const glm::mat4 &mat) const;
    void setVec3Value(const std::string &name, const glm::vec3 &vec) const;

private:
    unsigned int programID;

    unsigned int compileShader(const char* shaderSource, GLenum shaderType);
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif // SHADERMANAGER_H
