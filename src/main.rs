use std::mem::size_of;
use std::os::raw::c_int;
use std::os::raw::c_uchar;
use std::vec;

use libc::printf;

#[link(name = "sm4")]
extern "C" {
    fn sm4_enc(
        key: *const c_uchar,
        iv: *const c_uchar,
        r#in: *mut c_uchar,
        inlen: c_int,
        out: *mut c_uchar,
        outlen: *mut c_int,
    ) -> c_int;

    fn sm4_dec(
        key: *const c_uchar,
        iv: *const c_uchar,
        r#in: *const c_uchar,
        inlen: c_int,
        out: *mut c_uchar,
        outlen: *mut c_int,
    ) -> c_int;
}

fn sm4_encrypt(
    key: &'static str,
    iv: &str,
    in_str: &mut str,
    inlen: i32,
    out: &mut str,
    outlen: & mut i32,
) -> i32 {

    unsafe {
        sm4_enc(
            key.as_ptr(),
            iv.as_ptr(),
            in_str.as_mut_ptr(),
            inlen,
            out.as_mut_ptr(),
            outlen as *mut i32,
        )
    }
}
fn sm4_decrypt(
    key: &'static str,
    iv: &'static str,
    in_str: &'static str,
    inlen: i32,
    out: &mut str,
    outlen: &mut i32,
) -> i32 {
    unsafe {

        sm4_dec(
            key.as_ptr(),
            iv.as_ptr(),
            in_str.as_ptr(),
            inlen,
            out.as_mut_ptr(),
            outlen as  *mut i32
        )
    }
}

fn main() {
    const KEY_BYTES: [u8; 16] = [
        0x3f, 0x34, 0x2e, 0x9d, 0x67, 0xd6, 0xce, 0x7b, 0xe7, 0x01, 0x75, 0x6a, 0xf7, 0xba, 0xc8,
        0xf2,
    ];
    let key = unsafe { std::str::from_utf8_unchecked(&KEY_BYTES) };

    const IV_BYTES: [u8; 16] = [
        0x1f, 0xb2, 0xd4, 0x2f, 0xb3, 0x6e, 0x2e, 0x88, 0xa2, 0x20, 0xb0, 0x4f, 0x2e, 0x49, 0xaa,
        0x13,
    ];
    let iv = unsafe { std::str::from_utf8_unchecked(&IV_BYTES) };

    const IN_STR_BYTES: [u8; 16] = [
        0xe2, 0x44, 0xdb, 0xeb, 0x97, 0x58, 0x83, 0x1e, 0xa8, 0x7b, 0x7c, 0xeb, 0x27, 0x8e, 0x6e,
        0x5d,
    ];
    let in_str = unsafe { std::str::from_utf8_unchecked(&IN_STR_BYTES) };

    let mut outlen = 0;
    let mut _ret = 0;
    let inlen = in_str.len() as i32;
    let out_bytes = vec![0u8; inlen as usize];
    let mut out = unsafe { String::from_utf8_unchecked(out_bytes) };

    sm4_decrypt(&key, &iv, &in_str, inlen, &mut out, &mut outlen);

    println!("{} {} {:?}", out.len(), &outlen, out);
}
