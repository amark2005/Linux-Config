return {
  {
    "neovim/nvim-lspconfig",

    ft = { "rust" }, -- ONLY load for rust files

    opts = {
      servers = {
        rust_analyzer = {
          root_dir = require("lspconfig.util").root_pattern(
            "Cargo.toml",
            ".git"
          ),

          settings = {
            ["rust-analyzer"] = {
              cargo = {
                allFeatures = true,
              },

              checkOnSave = {
                command = "clippy",
              },
            },
          },
        },
      },
    },
  },

  {
    "simrat39/rust-tools.nvim",
    ft = { "rust" }, -- lazy-load only on rust files
    dependencies = {
      "neovim/nvim-lspconfig",
    },
    config = function()
      require("rust-tools").setup({})
    end,
  },
}
