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


};



#endif //VULKAN_APPLICATION_H
