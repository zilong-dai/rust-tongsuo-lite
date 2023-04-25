use std::path::PathBuf;

fn main() {
    let config_path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    println!(r"cargo:rustc-link-search={}/src/", config_path.to_string_lossy());
}