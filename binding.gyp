{
  "targets": [
    {
      "target_name": "xinput",
      "sources": ["src/xinput_win.cpp"],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
