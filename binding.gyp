{
  "targets": [
    {
      "target_name": "xboxCtrl",
      "sources": [
        "src/index.cc",
        "src/Off.cc",
        "src/List.cc",
        "src/Vibrate.cc"
      ],
      "include_dirs": [
        "src",
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
