#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x568fba06, "module_layout" },
	{ 0x87d591c5, "__pci_register_driver" },
	{ 0xd4dd3418, "__register_chrdev" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xb1b13d8f, "pci_unregister_driver" },
	{ 0xd6b8e852, "request_threaded_irq" },
	{ 0x50720c5f, "snprintf" },
	{ 0x67eec73, "pci_enable_msix" },
	{ 0x7a172b67, "kmem_cache_alloc_trace" },
	{ 0x4d884691, "malloc_sizes" },
	{ 0x6395be94, "__init_waitqueue_head" },
	{ 0x55b27fd, "pci_iomap" },
	{ 0xe67d9c7, "pci_request_regions" },
	{ 0xc1211685, "pci_enable_device" },
	{ 0x77e2f33, "_copy_from_user" },
	{ 0x71de9b3f, "_copy_to_user" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xfa66f77c, "finish_wait" },
	{ 0x1000e51, "schedule" },
	{ 0x5c8b5ce8, "prepare_to_wait" },
	{ 0x9021c4eb, "current_task" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x9f6b4c62, "down_interruptible" },
	{ 0xb80dc366, "remap_pfn_range" },
	{ 0x68aca4ad, "down" },
	{ 0xcf21d241, "__wake_up" },
	{ 0x71e3cecb, "up" },
	{ 0xeb560280, "pci_disable_device" },
	{ 0x5f39b0d8, "pci_release_regions" },
	{ 0xa22e0767, "pci_iounmap" },
	{ 0xf20dabd8, "free_irq" },
	{ 0x27e1a049, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("pci:v00001AF4d00001110sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "B580336AC23D885D8B5C55A");
