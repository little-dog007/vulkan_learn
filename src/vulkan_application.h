//
// Created by 86043 on 26-1-12.
//

#ifndef VULKAN_APPLICATION_H
#define VULKAN_APPLICATION_H

#include <vector>
#include <windows.h>
#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>


// https://geek-docs.com/vulkan/vulkan-tutorial/vulkan-physical-devices-and-queue-clusters.html
class VulkanApplication {
    public:
    void Run();
    void DrawFrame();

private:
    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    void InitWindow();
    void InitVulkan();

    void CreateInstance();
    void CreateSurface();
    void PickPhysicalDevice();
    void CreateLogicalDevice();
    void CreateSwapChain();
    bool isDeviceSuitable(VkPhysicalDevice device);

    void MainLoop();
    void Cleanup();

    bool checkValidationLayerSupport();
    void SetupDebugMessenger();
    bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
    SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
    void CreateImageViews();
    void CreateGraphicsPipeline();
    VkShaderModule CreateShaderModule(const std::vector<char>& code);
    void CreateRenderPass();
    void CreateFramebuffers();
    void CreateCommandPool();
    void CreateCommandBuffers();
    void CreateSemaphores();
    void CreateVertexBuffer();
    void CreateIndexBuffer();
    void CreateDescriptorSetLayout();
    void CreateUniformBuffer();
    void UpdateUniformBuffer();
    void CreateDescriptorPool();
    void CreateDescriptorSet();
    void CreateTextureImage();
    VkCommandBuffer BeginSingleTimeCommands();
    void EndSingleTimeCommands(VkCommandBuffer commandBuffer);

    void TransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
    void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);


    void CreateImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);


    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) ;
    void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    void CreateTextureImageView();
    VkImageView CreateImageView(VkImage image, VkFormat format);
    void CreateTextureSampler();

    HWND window_ = nullptr;
    VkInstance instance_ = VK_NULL_HANDLE;
    // 当VkInstance销毁时，这个对象将会被隐式销毁，所以我们并不需要在cleanup函数中做任何操作
    VkPhysicalDevice physicalDevice_ = VK_NULL_HANDLE;
    // 在选择要使用的物理设备之后，我们需要设置一个逻辑设备用于交互
    VkDevice device_ = VK_NULL_HANDLE;
    VkQueue graphicsQueue_ = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT debugMessenger_;
    VkSurfaceKHR surface_ = VK_NULL_HANDLE;
    VkQueue presentQueue_ = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain_ = VK_NULL_HANDLE;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    VkPipeline graphicsPipeline_ = VK_NULL_HANDLE;
    VkRenderPass renderPass_ = VK_NULL_HANDLE;

    VkPipelineLayout pipelineLayout_ = VK_NULL_HANDLE;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool_ = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> commandBuffers_;

    VkSemaphore imageAvailableSemaphore_;
    VkSemaphore renderFinishedSemaphore_;

    VkBuffer vertexBuffer_ = VK_NULL_HANDLE;
    VkDeviceMemory vertexBufferMemory_   = VK_NULL_HANDLE;
    VkBuffer indexBuffer_;
    VkDeviceMemory indexBufferMemory_;
    VkDescriptorSetLayout descriptorSetLayout_= VK_NULL_HANDLE;
    VkBuffer uniformBuffer_ = VK_NULL_HANDLE;
    VkDeviceMemory uniformBufferMemory_ = VK_NULL_HANDLE;
    VkDescriptorPool descriptorPool_ = VK_NULL_HANDLE;
    VkDescriptorSet descriptorSet_ = VK_NULL_HANDLE;
    VkImage textureImage_ = VK_NULL_HANDLE;
    VkDeviceMemory textureImageMemory_ = VK_NULL_HANDLE;
    VkImageView textureImageView_ = VK_NULL_HANDLE;
    VkSampler textureSampler_ = VK_NULL_HANDLE;

};



#endif //VULKAN_APPLICATION_H
