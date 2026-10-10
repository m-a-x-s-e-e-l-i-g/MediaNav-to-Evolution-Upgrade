/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40945dc8 FUN_40945dc8 */

/* Boundary evidence: original MIPS .pdata 40945dc8..40945f03. Semantic name remains unreviewed. */

int FUN_40945dc8(HMODULE param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40958b24 != (code *)0x0) {
      iVar2 = (*DAT_40958b24)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40945e78;
    FUN_40946134();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40951d20(param_1,param_2,param_3,param_4);
  }
LAB_40945e78:
  if (((param_2 == 0) && (FUN_409460bc(), iVar1 != 0)) && (DAT_40958b24 != (code *)0x0)) {
    iVar1 = (*DAT_40958b24)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40945f04 FUN_40945f04 */

/* Boundary evidence: original MIPS .pdata 40945f04..40945f2f. Semantic name remains unreviewed. */

void FUN_40945f04(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40945f30 entry */

/* Boundary evidence: original MIPS .pdata 40945f30..40945f87. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == 1) {
    FUN_40946170();
  }
  FUN_40945dc8(param_1,param_2,param_3,param_4);
  return;
}



/* 40945f88 FUN_40945f88 */

/* Boundary evidence: original MIPS .pdata 40945f88..40945fcf. Semantic name remains unreviewed. */

void FUN_40945f88(uint param_1)

{
  if ((param_1 == DAT_4095827c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40945fd0 FUN_40945fd0 */

/* Boundary evidence: original MIPS .pdata 40945fd0..409460bb. Semantic name remains unreviewed. */

void FUN_40945fd0(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40958ae0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40958b20;
    if (DAT_40958b20 != (undefined4 *)0x0) {
      while (DAT_40958b1c = DAT_40958b1c + -1, _Memory <= DAT_40958b1c) {
        if ((code *)*DAT_40958b1c != (code *)0x0) {
          (*(code *)*DAT_40958b1c)();
          _Memory = DAT_40958b20;
        }
      }
      free(_Memory);
      DAT_40958b1c = (undefined4 *)0x0;
      DAT_40958b20 = (undefined4 *)0x0;
    }
    FUN_409460e0((undefined4 *)&DAT_40941010,(undefined4 *)&DAT_40941014);
  }
  FUN_409460e0((undefined4 *)&DAT_40941018,(undefined4 *)&DAT_4094101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 409460bc FUN_409460bc */

/* Boundary evidence: original MIPS .pdata 409460bc..409460df. Semantic name remains unreviewed. */

void FUN_409460bc(void)

{
  FUN_40945fd0(0,0,1);
  return;
}



/* 409460e0 FUN_409460e0 */

/* Boundary evidence: original MIPS .pdata 409460e0..40946133. Semantic name remains unreviewed. */

void FUN_409460e0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40946134 FUN_40946134 */

/* Boundary evidence: original MIPS .pdata 40946134..4094616f. Semantic name remains unreviewed. */

void FUN_40946134(void)

{
  FUN_409460e0((undefined4 *)&DAT_40941008,(undefined4 *)&DAT_4094100c);
  FUN_409460e0((undefined4 *)&DAT_40941000,(undefined4 *)&DAT_40941004);
  return;
}



/* 40946170 FUN_40946170 */

/* Boundary evidence: original MIPS .pdata 40946170..409461e3. Semantic name remains unreviewed. */

void FUN_40946170(void)

{
  uint uVar1;
  
  if ((DAT_4095827c == 0) || (DAT_4095827c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4095827c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4095827c == 0) {
      DAT_4095827c = 0xb064;
    }
  }
  DAT_40958280 = ~DAT_4095827c;
  return;
}



/* 40946274 FUN_40946274 */

/* Boundary evidence: original MIPS .pdata 40946274..409462f7. Semantic name remains unreviewed. */

void FUN_40946274(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((HMODULE)*param_1 != (HMODULE)0x0) {
      FreeLibrary((HMODULE)*param_1);
      *param_1 = 0;
    }
    if ((HMODULE)param_1[1] != (HMODULE)0x0) {
      FreeLibrary((HMODULE)param_1[1]);
      param_1[1] = 0;
    }
    if ((HMODULE)param_1[2] != (HMODULE)0x0) {
      FreeLibrary((HMODULE)param_1[2]);
      param_1[2] = 0;
    }
  }
  return;
}



/* 409462f8 FUN_409462f8 */

/* Boundary evidence: original MIPS .pdata 409462f8..409469eb. Semantic name remains unreviewed. */

void FUN_409462f8(int param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  FILE *_File;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  
  FUN_40955a14();
  if (param_2 == 1) {
    uVar5 = *(undefined4 *)(param_1 + 4);
  }
  else {
    if (param_2 != 2) goto LAB_409469e0;
    uVar5 = *(undefined4 *)(param_1 + 8);
  }
  iVar1 = GetProcAddressW(uVar5,L"_gles_initialize");
  iVar4 = (param_2 + -1) * 0x4c + param_1;
  *(int *)(iVar4 + 0x18) = iVar1;
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    _File = (FILE *)getstdfilex(2);
    pcVar3 = "_gles_initialize";
  }
  else {
    iVar1 = GetProcAddressW(uVar5,L"_gles_shutdown");
    *(int *)(iVar4 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      DVar2 = GetLastError();
      _File = (FILE *)getstdfilex(2);
      pcVar3 = "_gles_shutdown";
    }
    else {
      iVar1 = GetProcAddressW(uVar5,L"_gles_make_current");
      *(int *)(iVar4 + 0x20) = iVar1;
      if (iVar1 == 0) {
        DVar2 = GetLastError();
        _File = (FILE *)getstdfilex(2);
        pcVar3 = "_gles_make_current";
      }
      else {
        iVar1 = GetProcAddressW(uVar5,L"_gles_finish");
        *(int *)(iVar4 + 0x24) = iVar1;
        if (iVar1 == 0) {
          DVar2 = GetLastError();
          _File = (FILE *)getstdfilex(2);
          pcVar3 = "_gles_finish";
        }
        else {
          iVar1 = GetProcAddressW(uVar5,L"_gles_flush");
          *(int *)(iVar4 + 0x28) = iVar1;
          if (iVar1 == 0) {
            DVar2 = GetLastError();
            _File = (FILE *)getstdfilex(2);
            pcVar3 = "_gles_flush";
          }
          else {
            iVar1 = GetProcAddressW(uVar5,L"_gles_set_draw_frame_builder");
            *(int *)(iVar4 + 0x2c) = iVar1;
            if (iVar1 == 0) {
              DVar2 = GetLastError();
              _File = (FILE *)getstdfilex(2);
              pcVar3 = "_gles_set_draw_frame_builder";
            }
            else {
              iVar1 = GetProcAddressW(uVar5,L"_gles_set_read_frame_builder");
              *(int *)(iVar4 + 0x30) = iVar1;
              if (iVar1 == 0) {
                DVar2 = GetLastError();
                _File = (FILE *)getstdfilex(2);
                pcVar3 = "_gles_set_read_frame_builder";
              }
              else {
                iVar1 = GetProcAddressW(uVar5,L"glViewport");
                *(int *)(iVar4 + 0x34) = iVar1;
                if (iVar1 == 0) {
                  DVar2 = GetLastError();
                  _File = (FILE *)getstdfilex(2);
                  pcVar3 = "glViewport";
                }
                else {
                  iVar1 = GetProcAddressW(uVar5,L"glScissor");
                  *(int *)(iVar4 + 0x38) = iVar1;
                  if (iVar1 == 0) {
                    DVar2 = GetLastError();
                    _File = (FILE *)getstdfilex(2);
                    pcVar3 = "glScissor";
                  }
                  else {
                    iVar1 = GetProcAddressW(uVar5,L"glCopyTexImage2D");
                    *(int *)(iVar4 + 0x40) = iVar1;
                    if (iVar1 == 0) {
                      DVar2 = GetLastError();
                      _File = (FILE *)getstdfilex(2);
                      pcVar3 = "glCopyTexImage2D";
                    }
                    else {
                      iVar1 = GetProcAddressW(uVar5,L"glGetError");
                      *(int *)(iVar4 + 0x3c) = iVar1;
                      if (iVar1 == 0) {
                        DVar2 = GetLastError();
                        _File = (FILE *)getstdfilex(2);
                        pcVar3 = "glGetError";
                      }
                      else {
                        iVar1 = GetProcAddressW(uVar5,L"glEGLImageTargetTexture2DOES");
                        *(int *)(iVar4 + 0x58) = iVar1;
                        if (iVar1 == 0) {
                          DVar2 = GetLastError();
                          _File = (FILE *)getstdfilex(2);
                          pcVar3 = "glEGLImageTargetTexture2DOES";
                        }
                        else if (param_2 == 1) {
                          iVar1 = GetProcAddressW(uVar5,L"_gles1_create_context");
                          *(int *)(iVar4 + 0x10) = iVar1;
                          if (iVar1 == 0) {
                            DVar2 = GetLastError();
                            _File = (FILE *)getstdfilex(2);
                            pcVar3 = "_gles1_create_context";
                          }
                          else {
                            iVar1 = GetProcAddressW(uVar5,L"_gles1_delete_context");
                            *(int *)(iVar4 + 0x14) = iVar1;
                            if (iVar1 == 0) {
                              DVar2 = GetLastError();
                              _File = (FILE *)getstdfilex(2);
                              pcVar3 = "_gles1_delete_context";
                            }
                            else {
                              iVar1 = GetProcAddressW(uVar5,L"_gles1_get_proc_address");
                              *(int *)(iVar4 + 0x4c) = iVar1;
                              if (iVar1 == 0) {
                                DVar2 = GetLastError();
                                _File = (FILE *)getstdfilex(2);
                                pcVar3 = "_gles1_get_proc_address";
                              }
                              else {
                                iVar1 = GetProcAddressW(uVar5,L"_gles1_bind_tex_image");
                                *(int *)(iVar4 + 0x44) = iVar1;
                                if (iVar1 == 0) {
                                  DVar2 = GetLastError();
                                  _File = (FILE *)getstdfilex(2);
                                  pcVar3 = "_gles1_bind_tex_image";
                                }
                                else {
                                  iVar1 = GetProcAddressW(uVar5,L"_gles1_unbind_tex_image");
                                  *(int *)(iVar4 + 0x48) = iVar1;
                                  if (iVar1 == 0) {
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_gles1_unbind_tex_image";
                                  }
                                  else {
                                    iVar1 = GetProcAddressW(uVar5,
                                                  L"_gles_setup_egl_image_from_texture");
                                    *(int *)(iVar4 + 0x50) = iVar1;
                                    if (iVar1 != 0) goto LAB_409469e0;
LAB_409467e8:
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_gles_setup_egl_image_from_texture";
                                  }
                                }
                              }
                            }
                          }
                        }
                        else {
                          if (param_2 != 2) goto LAB_409469e0;
                          iVar1 = GetProcAddressW(uVar5,L"_gles2_bind_tex_image");
                          *(int *)(iVar4 + 0x44) = iVar1;
                          if (iVar1 == 0) {
                            DVar2 = GetLastError();
                            _File = (FILE *)getstdfilex(2);
                            pcVar3 = "_gles2_bind_tex_image";
                          }
                          else {
                            iVar1 = GetProcAddressW(uVar5,L"_gles2_unbind_tex_image");
                            *(int *)(iVar4 + 0x48) = iVar1;
                            if (iVar1 == 0) {
                              DVar2 = GetLastError();
                              _File = (FILE *)getstdfilex(2);
                              pcVar3 = "_gles2_unbind_tex_image";
                            }
                            else {
                              iVar1 = GetProcAddressW(uVar5,L"_gles2_create_context");
                              *(int *)(iVar4 + 0x10) = iVar1;
                              if (iVar1 == 0) {
                                DVar2 = GetLastError();
                                _File = (FILE *)getstdfilex(2);
                                pcVar3 = "_gles2_create_context";
                              }
                              else {
                                iVar1 = GetProcAddressW(uVar5,L"_gles2_delete_context");
                                *(int *)(iVar4 + 0x14) = iVar1;
                                if (iVar1 == 0) {
                                  DVar2 = GetLastError();
                                  _File = (FILE *)getstdfilex(2);
                                  pcVar3 = "_gles2_delete_context";
                                }
                                else {
                                  iVar1 = GetProcAddressW(uVar5,L"_gles2_get_proc_address");
                                  *(int *)(iVar4 + 0x4c) = iVar1;
                                  if (iVar1 == 0) {
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_gles2_get_proc_address";
                                  }
                                  else {
                                    iVar1 = GetProcAddressW(uVar5,
                                                  L"_gles_setup_egl_image_from_texture");
                                    *(int *)(iVar4 + 0x50) = iVar1;
                                    if (iVar1 == 0) goto LAB_409467e8;
                                    iVar1 = GetProcAddressW(uVar5,
                                                  L"_gles_setup_egl_image_from_renderbuffer");
                                    *(int *)(iVar4 + 0x54) = iVar1;
                                    if (iVar1 != 0) goto LAB_409469e0;
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_gles_setup_egl_image_from_renderbuffer";
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  fprintf(_File,"Failed to resolve address for %s (error 0x%x)\n",pcVar3,DVar2);
LAB_409469e0:
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x10);
}



/* 409469ec FUN_409469ec */

/* Boundary evidence: original MIPS .pdata 409469ec..4094704f. Semantic name remains unreviewed. */

undefined4 FUN_409469ec(undefined4 *param_1)

{
  int iVar1;
  DWORD DVar2;
  FILE *_File;
  char *pcVar3;
  
  iVar1 = GetProcAddressW(*param_1,L"_vg_is_valid_image_handle");
  param_1[0x2a] = iVar1;
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    _File = (FILE *)getstdfilex(2);
    pcVar3 = "_vg_is_valid_image_handle";
  }
  else {
    iVar1 = GetProcAddressW(*param_1,L"_vg_get_parent");
    param_1[0x2b] = iVar1;
    if (iVar1 == 0) {
      DVar2 = GetLastError();
      _File = (FILE *)getstdfilex(2);
      pcVar3 = "_vg_get_parent";
    }
    else {
      iVar1 = GetProcAddressW(*param_1,L"_vg_image_lock");
      param_1[0x2c] = iVar1;
      if (iVar1 == 0) {
        DVar2 = GetLastError();
        _File = (FILE *)getstdfilex(2);
        pcVar3 = "_vg_image_lock";
      }
      else {
        iVar1 = GetProcAddressW(*param_1,L"_vg_image_unlock");
        param_1[0x2d] = iVar1;
        if (iVar1 == 0) {
          DVar2 = GetLastError();
          _File = (FILE *)getstdfilex(2);
          pcVar3 = "_vg_image_unlock";
        }
        else {
          iVar1 = GetProcAddressW(*param_1,L"_vg_lock_image_ptrset");
          param_1[0x2e] = iVar1;
          if (iVar1 == 0) {
            DVar2 = GetLastError();
            _File = (FILE *)getstdfilex(2);
            pcVar3 = "_vg_lock_image_ptrset";
          }
          else {
            iVar1 = GetProcAddressW(*param_1,L"_vg_unlock_image_ptrset");
            param_1[0x2f] = iVar1;
            if (iVar1 == 0) {
              DVar2 = GetLastError();
              _File = (FILE *)getstdfilex(2);
              pcVar3 = "_vg_unlock_image_ptrset";
            }
            else {
              iVar1 = GetProcAddressW(*param_1,L"_vg_image_ref");
              param_1[0x30] = iVar1;
              if (iVar1 == 0) {
                DVar2 = GetLastError();
                _File = (FILE *)getstdfilex(2);
                pcVar3 = "_vg_image_ref";
              }
              else {
                iVar1 = GetProcAddressW(*param_1,L"_vg_image_deref");
                param_1[0x31] = iVar1;
                if (iVar1 == 0) {
                  DVar2 = GetLastError();
                  _File = (FILE *)getstdfilex(2);
                  pcVar3 = "_vg_image_deref";
                }
                else {
                  iVar1 = GetProcAddressW(*param_1,L"_vg_image_pbuffer_to_clientbuffer");
                  param_1[0x32] = iVar1;
                  if (iVar1 == 0) {
                    DVar2 = GetLastError();
                    _File = (FILE *)getstdfilex(2);
                    pcVar3 = "_vg_image_pbuffer_to_clientbuffer";
                  }
                  else {
                    iVar1 = GetProcAddressW(*param_1,L"_vg_image_match_egl_config");
                    param_1[0x33] = iVar1;
                    if (iVar1 == 0) {
                      DVar2 = GetLastError();
                      _File = (FILE *)getstdfilex(2);
                      pcVar3 = "_vg_image_match_egl_config";
                    }
                    else {
                      iVar1 = GetProcAddressW(*param_1,L"_vg_create_global_context");
                      param_1[0x34] = iVar1;
                      if (iVar1 == 0) {
                        DVar2 = GetLastError();
                        _File = (FILE *)getstdfilex(2);
                        pcVar3 = "_vg_create_global_context";
                      }
                      else {
                        iVar1 = GetProcAddressW(*param_1,L"_vg_destroy_global_context");
                        param_1[0x35] = iVar1;
                        if (iVar1 == 0) {
                          DVar2 = GetLastError();
                          _File = (FILE *)getstdfilex(2);
                          pcVar3 = "_vg_destroy_global_context";
                        }
                        else {
                          iVar1 = GetProcAddressW(*param_1,L"_vg_create_context");
                          param_1[0x36] = iVar1;
                          if (iVar1 == 0) {
                            DVar2 = GetLastError();
                            _File = (FILE *)getstdfilex(2);
                            pcVar3 = "_vg_create_context";
                          }
                          else {
                            iVar1 = GetProcAddressW(*param_1,L"_vg_destroy_context");
                            param_1[0x37] = iVar1;
                            if (iVar1 == 0) {
                              DVar2 = GetLastError();
                              _File = (FILE *)getstdfilex(2);
                              pcVar3 = "_vg_destroy_context";
                            }
                            else {
                              iVar1 = GetProcAddressW(*param_1,L"_vg_context_resize_aquire");
                              param_1[0x38] = iVar1;
                              if (iVar1 == 0) {
                                DVar2 = GetLastError();
                                _File = (FILE *)getstdfilex(2);
                                pcVar3 = "_vg_context_resize_aquire";
                              }
                              else {
                                iVar1 = GetProcAddressW(*param_1,L"_vg_context_resize_rollback");
                                param_1[0x39] = iVar1;
                                if (iVar1 == 0) {
                                  DVar2 = GetLastError();
                                  _File = (FILE *)getstdfilex(2);
                                  pcVar3 = "_vg_context_resize_rollback";
                                }
                                else {
                                  iVar1 = GetProcAddressW(*param_1,L"_vg_context_resize_finish");
                                  param_1[0x3a] = iVar1;
                                  if (iVar1 == 0) {
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_vg_context_resize_finish";
                                  }
                                  else {
                                    iVar1 = GetProcAddressW(*param_1,L"_vg_make_current");
                                    param_1[0x3b] = iVar1;
                                    if (iVar1 == 0) {
                                      DVar2 = GetLastError();
                                      _File = (FILE *)getstdfilex(2);
                                      pcVar3 = "_vg_make_current";
                                    }
                                    else {
                                      iVar1 = GetProcAddressW(*param_1,
                                                  L"_vg_context_wait_async_rendering");
                                      param_1[0x3c] = iVar1;
                                      if (iVar1 == 0) {
                                        DVar2 = GetLastError();
                                        _File = (FILE *)getstdfilex(2);
                                        pcVar3 = "_vg_context_wait_async_rendering";
                                      }
                                      else {
                                        iVar1 = GetProcAddressW(*param_1,L"_vg_finish_hal");
                                        param_1[0x3d] = iVar1;
                                        if (iVar1 == 0) {
                                          DVar2 = GetLastError();
                                          _File = (FILE *)getstdfilex(2);
                                          pcVar3 = "_vg_finish_hal";
                                        }
                                        else {
                                          iVar1 = GetProcAddressW(*param_1,L"_vg_get_proc_address");
                                          param_1[0x3e] = iVar1;
                                          if (iVar1 == 0) {
                                            DVar2 = GetLastError();
                                            _File = (FILE *)getstdfilex(2);
                                            pcVar3 = "_vg_get_proc_address";
                                          }
                                          else {
                                            iVar1 = GetProcAddressW(*param_1,
                                                  L"_vg_set_frame_builder");
                                            param_1[0x3f] = iVar1;
                                            if (iVar1 == 0) {
                                              DVar2 = GetLastError();
                                              _File = (FILE *)getstdfilex(2);
                                              pcVar3 = "_vg_set_frame_builder";
                                            }
                                            else {
                                              iVar1 = GetProcAddressW(*param_1,
                                                  L"_vg_setup_egl_image");
                                              param_1[0x40] = iVar1;
                                              if (iVar1 != 0) {
                                                return 1;
                                              }
                                              DVar2 = GetLastError();
                                              _File = (FILE *)getstdfilex(2);
                                              pcVar3 = "_vg_setup_egl_image";
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  fprintf(_File,"Failed to resolve address for %s (error 0x%x)\n",pcVar3,DVar2);
  return 0;
}



/* 40947050 FUN_40947050 */

/* Boundary evidence: original MIPS .pdata 40947050..4094713b. Semantic name remains unreviewed. */

undefined4 FUN_40947050(undefined4 *param_1)

{
  HMODULE pHVar1;
  int iVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x43] = 0x3038;
  pHVar1 = LoadLibraryW(L"libOpenVG.dll");
  *param_1 = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    iVar2 = FUN_409469ec(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    param_1[0x43] = param_1[0x43] | 2;
  }
  pHVar1 = LoadLibraryW(L"libGLESv1_CM.dll");
  param_1[1] = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    param_1[0x13] = 0;
    iVar2 = FUN_409462f8((int)param_1,1);
    if (iVar2 == 0) {
      return 0;
    }
    param_1[0x43] = param_1[0x43] | 1;
  }
  pHVar1 = LoadLibraryW(L"libGLESv2.dll");
  param_1[2] = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    param_1[0x26] = 0;
    iVar2 = FUN_409462f8((int)param_1,2);
    if (iVar2 == 0) {
      return 0;
    }
    param_1[0x43] = param_1[0x43] | 4;
    return 1;
  }
  return 1;
}



/* 40947148 FUN_40947148 */

/* Boundary evidence: original MIPS .pdata 40947148..409471b3. Semantic name remains unreviewed. */

void FUN_40947148(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 200) != 0) {
    piVar1 = FUN_409519bc();
    if ((*param_2 != 0) && (iVar2 = *(int *)(*param_2 + 0xc), iVar2 != 0)) {
      (**(code **)(piVar1[0xc] + 0xc4))(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(param_1 + 200))
      ;
    }
    *(undefined4 *)(param_1 + 200) = 0;
  }
  return;
}



/* 409471b4 FUN_409471b4 */

/* Boundary evidence: original MIPS .pdata 409471b4..40947217. Semantic name remains unreviewed. */

void FUN_409471b4(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  FUN_40955ae4();
  piVar1 = FUN_409519bc();
  (**(code **)(piVar1[0xc] + 200))(*(undefined4 *)(param_1 + 200),param_3);
  (**(code **)(piVar1[0xc] + 0xb4))(*(undefined4 *)(*(int *)(param_4 + 4) + 200));
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x10);
}



/* 40947218 FUN_40947218 */

/* Boundary evidence: original MIPS .pdata 40947218..4094726f. Semantic name remains unreviewed. */

undefined4 FUN_40947218(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  piVar1 = FUN_409519bc();
  if (((*(uint *)(piVar1[0xc] + 0x10c) & 2) == 0) ||
     (pcVar3 = *(code **)(piVar1[0xc] + 0xf8), pcVar3 == (code *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*pcVar3)(param_2);
  }
  return uVar2;
}



/* 40947270 FUN_40947270 */

/* Boundary evidence: original MIPS .pdata 40947270..409472f3. Semantic name remains unreviewed. */

void FUN_40947270(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  (**(code **)(piVar1[0xc] + 0x100))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 409472f4 FUN_409472f4 */

/* Boundary evidence: original MIPS .pdata 409472f4..40947327. Semantic name remains unreviewed. */

void FUN_409472f4(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  (**(code **)(piVar1[0xc] + 0xf4))(*(undefined4 *)(param_1 + 0x18));
  return;
}



/* 40947328 FUN_40947328 */

/* Boundary evidence: original MIPS .pdata 40947328..4094735b. Semantic name remains unreviewed. */

void FUN_40947328(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  (**(code **)(piVar1[0xc] + 0xf0))(*(undefined4 *)(param_1 + 0x18));
  return;
}



/* 4094735c FUN_4094735c */

/* Boundary evidence: original MIPS .pdata 4094735c..409473b3. Semantic name remains unreviewed. */

bool FUN_4094735c(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_409519bc();
  iVar2 = (**(code **)(piVar1[0xc] + 0xfc))
                    (*(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_1 + 8));
  return iVar2 != 0;
}



/* 409473b4 FUN_409473b4 */

/* Boundary evidence: original MIPS .pdata 409473b4..4094743f. Semantic name remains unreviewed. */

void FUN_409473b4(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  if (*(int *)(param_1 + 0x18) != 0) {
    (**(code **)(piVar1[0xc] + 0xf4))();
    (**(code **)(piVar1[0xc] + 0xfc))(*(undefined4 *)(param_1 + 0x18),0);
    (**(code **)(piVar1[0xc] + 0xec))(0,0,3,0,0,0,0,0,0);
  }
  return;
}



/* 40947440 FUN_40947440 */

/* Boundary evidence: original MIPS .pdata 40947440..4094755f. Semantic name remains unreviewed. */

void FUN_40947440(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  FUN_40955ae4();
  piVar1 = FUN_409519bc();
  if ((((*(int *)(param_4 + 0xc) == 0x30a1) &&
       (iVar2 = (**(code **)(piVar1[0xc] + 0xec))
                          (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 8),
                           *(undefined4 *)(param_2 + 0xc),
                           *(undefined4 *)(*(int *)(param_2 + 0xb8) + 100)), iVar2 != 0)) &&
      (*(int *)(param_2 + 200) != 0)) &&
     ((param_3 == 1 && (iVar2 = (**(code **)(piVar1[0xc] + 0xb0))(), iVar2 == 0)))) {
    (**(code **)(piVar1[0xc] + 0xec))(0,0,3,0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x28);
}



/* 40947560 FUN_40947560 */

/* Boundary evidence: original MIPS .pdata 40947560..409475d7. Semantic name remains unreviewed. */

void FUN_40947560(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  if (*(int *)(param_1 + 0x18) != 0) {
    (**(code **)(piVar1[0xc] + 0xf4))();
    (**(code **)(piVar1[0xc] + 0xec))(0,0,3,0,0,0,0,0,0);
  }
  return;
}



/* 409475d8 FUN_409475d8 */

/* Boundary evidence: original MIPS .pdata 409475d8..4094761f. Semantic name remains unreviewed. */

undefined4 FUN_409475d8(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  if (*(int *)(param_1 + 0xc) != 0) {
    (**(code **)(piVar1[0xc] + 0xdc))();
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 1;
}



/* 40947620 FUN_40947620 */

/* Boundary evidence: original MIPS .pdata 40947620..4094765b. Semantic name remains unreviewed. */

void FUN_40947620(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  (**(code **)(piVar1[0xc] + 0xe8))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094765c FUN_4094765c */

/* Boundary evidence: original MIPS .pdata 4094765c..40947697. Semantic name remains unreviewed. */

void FUN_4094765c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  (**(code **)(piVar1[0xc] + 0xe4))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 40947698 FUN_40947698 */

/* Boundary evidence: original MIPS .pdata 40947698..409476d3. Semantic name remains unreviewed. */

void FUN_40947698(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  (**(code **)(piVar1[0xc] + 0xe0))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 409476d4 FUN_409476d4 */

/* Boundary evidence: original MIPS .pdata 409476d4..4094781b. Semantic name remains unreviewed. */

undefined4 * FUN_409476d4(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  piVar1 = FUN_409519bc();
  if (((*(uint *)(param_1 + 0x5c) & 2) == 0) || ((*(uint *)(piVar1[0xc] + 0x10c) & 2) == 0)) {
    if (param_4 == 0) {
      return (undefined4 *)0x0;
    }
    *(undefined4 *)(param_4 + 0x10) = 0x3005;
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_40951f98(param_1,param_3);
  if (puVar2 == (undefined4 *)0x0) {
    if (param_4 == 0) {
      return (undefined4 *)0x0;
    }
    *(undefined4 *)(param_4 + 0x10) = 0x3003;
    return (undefined4 *)0x0;
  }
  if (param_2 != 0) {
    uVar4 = *(undefined4 *)(param_2 + 0xc);
  }
  puVar2[2] = 0x30a1;
  if (piVar1[0xd] == 0) {
    iVar3 = (**(code **)(piVar1[0xc] + 0xd0))(*(undefined4 *)(*(int *)(param_4 + 8) + 0x1c));
    piVar1[0xd] = iVar3;
    if (iVar3 == 0) goto LAB_40947798;
  }
  iVar3 = (**(code **)(piVar1[0xc] + 0xd8))
                    (*(undefined4 *)(*(int *)(param_4 + 8) + 0x1c),uVar4,piVar1[0xd]);
  puVar2[3] = iVar3;
  if (iVar3 != 0) {
    puVar2[10] = 1;
    return puVar2;
  }
LAB_40947798:
  *(undefined4 *)(param_4 + 0x10) = 0x3003;
  FUN_409520e8((int)puVar2);
  return (undefined4 *)0x0;
}



/* 4094781c FUN_4094781c */

/* Boundary evidence: original MIPS .pdata 4094781c..40947c1b. Semantic name remains unreviewed. */

void FUN_4094781c(int param_1,int param_2,undefined4 *param_3,int *param_4)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  int *piVar9;
  int iStack00000030;
  int iStack00000034;
  int iStack00000038;
  int iStack0000003c;
  undefined4 uStack00000040;
  undefined4 uStack00000044;
  int *in_stack_00000080;
  
  FUN_40955a74();
  uStack00000040 = 0;
  iStack00000038 = 0;
  iStack0000003c = 0;
  uStack00000044 = 0x10;
  iStack00000030 = 0;
  iStack00000034 = 0;
  piVar2 = FUN_409519bc();
  if (in_stack_00000080[3] == 0x30a0) {
    iVar4 = in_stack_00000080[1];
  }
  else {
    if (in_stack_00000080[3] != 0x30a1) goto LAB_40947c10;
    iVar4 = *in_stack_00000080;
  }
  if (iVar4 == 0) goto LAB_40947c10;
  if ((*in_stack_00000080 == 0) || (iVar4 = *(int *)(*in_stack_00000080 + 0xc), iVar4 == 0)) {
    in_stack_00000080[4] = 0x3002;
    goto LAB_40947c10;
  }
  (**(code **)(piVar2[0xc] + 0xb8))(*(undefined4 *)(iVar4 + 0xc));
  iVar4 = (**(code **)(piVar2[0xc] + 0xa8))
                    (*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc),param_2);
  if (iVar4 == 0) {
    iVar4 = 0x300c;
LAB_409478dc:
    in_stack_00000080[4] = iVar4;
    pcVar7 = *(code **)(piVar2[0xc] + 0xbc);
  }
  else {
    bVar1 = FUN_4094ad6c(param_1,*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc),param_2,
                         0x30ba);
    if ((CONCAT31(extraout_var,bVar1) == 1) || (iVar4 = FUN_4094b544(param_2), iVar4 == 1)) {
      iVar4 = 0x3002;
      goto LAB_409478dc;
    }
    if ((param_3[0x17] & 2) == 0) {
      in_stack_00000080[4] = 0x3009;
      (**(code **)(piVar2[0xc] + 0xbc))(*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc));
      goto LAB_40947c10;
    }
    iVar4 = (**(code **)(piVar2[0xc] + 0xcc))(param_2,*param_3,param_3[1],param_3[2]);
    if (iVar4 == 0) {
      iVar4 = 0x3009;
      goto LAB_409478dc;
    }
    iVar4 = 0;
    if (param_4 != (int *)0x0) {
      iVar5 = *param_4;
      piVar3 = param_4;
      while (iVar5 != 0x3038) {
        prefetch(piVar3 + 4,0);
        iVar4 = iVar4 + 2;
        iVar5 = piVar3[2];
        piVar3 = piVar3 + 2;
      }
    }
    piVar3 = (int *)mali_sys_malloc((iVar4 + 9) * 4);
    if (piVar3 != (int *)0x0) {
      iVar4 = 0;
      iVar5 = 0;
      if (param_4 != (int *)0x0) {
        iVar6 = *param_4;
        piVar9 = piVar3;
        piVar8 = param_4;
        while (iVar6 != 0x3038) {
          iVar6 = *piVar8;
          if ((iVar6 < 0x3056) || ((0x3057 < iVar6 && ((iVar6 < 0x3087 || (0x3088 < iVar6)))))) {
            *piVar9 = iVar6;
            iVar5 = iVar5 + 2;
            piVar9[1] = piVar8[1];
            piVar9 = piVar9 + 2;
          }
          iVar4 = iVar4 + 2;
          piVar8 = param_4 + iVar4;
          iVar6 = *piVar8;
        }
      }
      piVar3[iVar5] = 0x3057;
      piVar3[iVar5 + 1] = iStack00000030;
      piVar3[iVar5 + 2] = 0x3056;
      piVar3[iVar5 + 3] = iStack00000034;
      piVar3[iVar5 + 4] = 0x3087;
      iVar4 = 0x308a;
      if (iStack00000038 != 1) {
        iVar4 = 0x3089;
      }
      piVar3[iVar5 + 5] = iVar4;
      piVar3[iVar5 + 6] = 0x3088;
      iVar4 = 0x308c;
      if (iStack0000003c != 1) {
        iVar4 = 0x308b;
      }
      piVar3[iVar5 + 7] = iVar4;
      (piVar3 + iVar5 + 7)[1] = 0x3038;
      iVar4 = FUN_4094d994(in_stack_00000080,param_1,1,(int)param_3);
      mali_sys_free(piVar3);
      if (iVar4 != 0) {
        (**(code **)(piVar2[0xc] + 0xc0))
                  (*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc),param_2);
        *(int *)(iVar4 + 200) = param_2;
      }
      (**(code **)(piVar2[0xc] + 0xbc))(*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc));
      goto LAB_40947c10;
    }
    in_stack_00000080[4] = 0x3003;
    mali_sys_free(0);
    pcVar7 = *(code **)(piVar2[0xc] + 0xbc);
  }
  (*pcVar7)(*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc));
LAB_40947c10:
                    /* WARNING: Subroutine does not return */
  FUN_40955aac(0x48);
}



/* 40947c1c FUN_40947c1c */

/* Boundary evidence: original MIPS .pdata 40947c1c..40947c5b. Semantic name remains unreviewed. */

void FUN_40947c1c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_2 + 4) + 0xc);
  (**(code **)(*(int *)(iVar1 + 0x18) * 0x4c + *(int *)(*(int *)(param_2 + 8) + 0x30) + -4))
            (*(undefined4 *)(iVar1 + 0xc));
  return;
}



/* 40947ca0 FUN_40947ca0 */

/* Boundary evidence: original MIPS .pdata 40947ca0..40947cff. Semantic name remains unreviewed. */

void FUN_40947ca0(int param_1)

{
  if ((*(uint *)(*(int *)(param_1 + 0x30) + 0x10c) & 1) != 0) {
    (**(code **)(*(int *)(param_1 + 0x30) + 0x1c))(param_1 + 0x38);
  }
  if ((*(uint *)(*(int *)(param_1 + 0x30) + 0x10c) & 4) != 0) {
    (**(code **)(*(int *)(param_1 + 0x30) + 0x68))(param_1 + 0x38);
  }
  return;
}



/* 40947d00 FUN_40947d00 */

/* Boundary evidence: original MIPS .pdata 40947d00..40947d73. Semantic name remains unreviewed. */

int FUN_40947d00(int param_1)

{
  int iVar1;
  
  if ((((*(uint *)(*(int *)(param_1 + 0x30) + 0x10c) & 1) == 0) ||
      (iVar1 = (**(code **)(*(int *)(param_1 + 0x30) + 0x18))(param_1 + 0x38), iVar1 == 0)) &&
     (((*(uint *)(*(int *)(param_1 + 0x30) + 0x10c) & 4) == 0 ||
      (iVar1 = (**(code **)(*(int *)(param_1 + 0x30) + 100))(param_1 + 0x38), iVar1 == 0)))) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40947d74 FUN_40947d74 */

/* Boundary evidence: original MIPS .pdata 40947d74..40947dfb. Semantic name remains unreviewed. */

void FUN_40947d74(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  
  piVar1 = FUN_409519bc();
  iVar2 = 0;
  if (((*(uint *)(piVar1[0xc] + 0x10c) & 1) != 0) &&
     (pcVar3 = *(code **)(piVar1[0xc] + 0x4c), pcVar3 != (code *)0x0)) {
    iVar2 = (*pcVar3)(param_2);
  }
  if ((((*(uint *)(piVar1[0xc] + 0x10c) & 4) != 0) &&
      (pcVar3 = *(code **)(piVar1[0xc] + 0x98), pcVar3 != (code *)0x0)) && (iVar2 == 0)) {
    (*pcVar3)(param_2);
  }
  return;
}



/* 40947dfc FUN_40947dfc */

/* Boundary evidence: original MIPS .pdata 40947dfc..40947fbb. Semantic name remains unreviewed. */

undefined4
FUN_40947dfc(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  piVar1 = FUN_409519bc();
  iVar2 = *(int *)(param_1 + 0x18);
  switch(param_2) {
  case 0x30b1:
    uVar3 = 1;
    break;
  case 0x30b3:
    uVar3 = 2;
    break;
  case 0x30b4:
    uVar3 = 3;
    break;
  case 0x30b5:
    uVar3 = 4;
    break;
  case 0x30b6:
    uVar3 = 5;
    break;
  case 0x30b7:
    uVar3 = 6;
    break;
  case 0x30b8:
    uVar3 = 7;
    break;
  case 0x30b9:
    uVar3 = 8;
  }
  if (param_2 == 0x30b9) {
    if (iVar2 == 1) {
      return 0x3000;
    }
    if (iVar2 != 2) {
      return 0x3000;
    }
    iVar2 = (**(code **)(piVar1[0xc] + 0xa0))(*(undefined4 *)(param_1 + 0xc),param_3,param_5);
  }
  else {
    iVar2 = (**(code **)(piVar1[0xc] + (iVar2 + -1) * 0x4c + 0x50))
                      (*(undefined4 *)(param_1 + 0xc),uVar3,param_3,param_4,param_5);
  }
  if (iVar2 == 1) {
    return 0x3009;
  }
  if (1 < iVar2) {
    if (iVar2 < 5) {
      return 0x300c;
    }
    if (iVar2 == 5) {
      return 0x3002;
    }
    if (iVar2 == 6) {
      return 0x3003;
    }
  }
  return 0x3000;
}



/* 40947fbc FUN_40947fbc */

/* Boundary evidence: original MIPS .pdata 40947fbc..40948007. Semantic name remains unreviewed. */

void FUN_40947fbc(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x18) * 0x4c + piVar1[0xc] + -0x28))
            (*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 40948008 FUN_40948008 */

/* Boundary evidence: original MIPS .pdata 40948008..40948053. Semantic name remains unreviewed. */

void FUN_40948008(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x18) * 0x4c + piVar1[0xc] + -0x24))
            (*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 40948054 FUN_40948054 */

/* Boundary evidence: original MIPS .pdata 40948054..409481c3. Semantic name remains unreviewed. */

void FUN_40948054(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_40955ae4();
  uVar4 = 0x1907;
  piVar1 = FUN_409519bc();
  iVar3 = *(int *)(*(int *)(*(int *)(param_2 + 4) + 0xc) + 0x18);
  if ((*(int *)(param_1 + 0xf0) != 0x305d) && (*(int *)(param_1 + 0xf0) == 0x305e)) {
    uVar4 = 0x1908;
  }
  iVar2 = __mali_pixel_format_get_bpp(*(undefined4 *)(*(int *)(param_1 + 0xb8) + 0x80));
  if ((iVar2 * *(int *)(param_1 + 0xbc) & 0xfffffff8U) < 0x200) {
    uVar4 = 0x3009;
  }
  else {
    iVar3 = (iVar3 + -1) * 0x4c;
    (**(code **)(iVar3 + piVar1[0xc] + 0x24))
              (*(undefined4 *)(*(int *)(*(int *)(param_2 + 4) + 0xc) + 0xc));
    (**(code **)(iVar3 + piVar1[0xc] + 0x3c))();
    iVar2 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
    if ((iVar2 == 0) || (iVar2 = mali_render_attachment_get_target(iVar2,0,0), iVar2 == 0))
    goto LAB_409481bc;
    (**(code **)(iVar3 + piVar1[0xc] + 0x44))
              (*(undefined4 *)(*(int *)(*(int *)(param_2 + 4) + 0xc) + 0xc),0xde1,
               *(undefined4 *)(param_1 + 0xdc),uVar4);
    iVar3 = (**(code **)(iVar3 + piVar1[0xc] + 0x3c))();
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0xfc) = 1;
      goto LAB_409481bc;
    }
    if (iVar3 != 0x505) {
      *(undefined4 *)(param_2 + 0x10) = 0x300c;
      goto LAB_409481bc;
    }
    uVar4 = 0x3003;
  }
  *(undefined4 *)(param_2 + 0x10) = uVar4;
LAB_409481bc:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 409481c4 FUN_409481c4 */

/* Boundary evidence: original MIPS .pdata 409481c4..4094827b. Semantic name remains unreviewed. */

bool FUN_409481c4(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_409519bc();
  iVar2 = *(int *)(param_1 + 0xb8);
  iVar2 = (**(code **)((*(int *)(*(int *)(*(int *)(param_2 + 4) + 0xc) + 0x18) + -1) * 0x4c +
                       piVar1[0xc] + 0x2c))
                    (*(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_1 + 8),
                     *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(iVar2 + 4),
                     *(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc),
                     *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x34),
                     *(undefined4 *)(iVar2 + 0x68),*(undefined4 *)(iVar2 + 100),
                     *(undefined4 *)(iVar2 + 0x60));
  return iVar2 == 0;
}



/* 4094827c FUN_4094827c */

/* Boundary evidence: original MIPS .pdata 4094827c..409482f3. Semantic name remains unreviewed. */

void FUN_4094827c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_409519bc();
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar1 = (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x18) + -1) * 0x4c;
    (**(code **)(piVar2[0xc] + iVar1 + 0x24))();
    (**(code **)(piVar2[0xc] + iVar1 + 0x20))(0);
  }
  return;
}



/* 409482f4 FUN_409482f4 */

/* Boundary evidence: original MIPS .pdata 409482f4..40948373. Semantic name remains unreviewed. */

void FUN_409482f4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_409519bc();
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 4) != 0)) {
    iVar1 = (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x18) + -1) * 0x4c;
    (**(code **)(iVar1 + piVar2[0xc] + 0x24))();
    (**(code **)(iVar1 + piVar2[0xc] + 0x20))(0);
  }
  return;
}



/* 40948374 FUN_40948374 */

/* Boundary evidence: original MIPS .pdata 40948374..409483cb. Semantic name remains unreviewed. */

undefined4 FUN_40948374(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  if (*(int *)(param_1 + 0xc) != 0) {
    (**(code **)(*(int *)(param_1 + 0x18) * 0x4c + piVar1[0xc] + -0x38))();
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 1;
}



/* 409483cc FUN_409483cc */

/* Boundary evidence: original MIPS .pdata 409483cc..40948467. Semantic name remains unreviewed. */

undefined4 FUN_409483cc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_409519bc();
  iVar1 = (*(int *)(param_1 + 0x18) + -1) * 0x4c;
  (**(code **)(piVar2[0xc] + iVar1 + 0x34))(0,0,param_2,param_3);
  (**(code **)(piVar2[0xc] + iVar1 + 0x38))(0,0,param_2,param_3);
  return 1;
}



/* 40948468 FUN_40948468 */

/* Boundary evidence: original MIPS .pdata 40948468..409484ff. Semantic name remains unreviewed. */

void FUN_40948468(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_409519bc();
  iVar1 = (*(int *)(param_1 + 0x18) + -1) * 0x4c;
  (**(code **)(piVar2[0xc] + iVar1 + 0x34))(0,0,param_2,param_3);
  (**(code **)(piVar2[0xc] + iVar1 + 0x38))(0,0,param_2,param_3);
  return;
}



/* 40948500 FUN_40948500 */

/* Boundary evidence: original MIPS .pdata 40948500..40948667. Semantic name remains unreviewed. */

undefined4 FUN_40948500(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = FUN_409519bc();
  if (*(int *)(param_4 + 0xc) != 0x30a0) {
    return 1;
  }
  iVar1 = (*(int *)(param_1 + 0x18) + -1) * 0x4c;
  (**(code **)(piVar2[0xc] + iVar1 + 0x20))(*(undefined4 *)(param_1 + 0xc));
  iVar3 = *(int *)(param_2 + 0xb8);
  iVar3 = (**(code **)(piVar2[0xc] + iVar1 + 0x2c))
                    (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 8),
                     *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(iVar3 + 4),
                     *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                     *(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x34),
                     *(undefined4 *)(iVar3 + 0x68),*(undefined4 *)(iVar3 + 100),
                     *(undefined4 *)(iVar3 + 0x60));
  if ((iVar3 == 0) &&
     (iVar3 = (**(code **)(piVar2[0xc] + iVar1 + 0x30))
                        (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_3 + 8),
                         *(undefined4 *)(param_3 + 0xc)), iVar3 == 0)) {
    if (*(int *)(param_1 + 0x10) != 0) {
      return 1;
    }
    iVar3 = FUN_409483cc(param_1,*(undefined4 *)(param_2 + 0xbc),*(undefined4 *)(param_2 + 0xc0));
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x10) = 1;
      return 1;
    }
    (**(code **)(piVar2[0xc] + iVar1 + 0x20))(0);
  }
  return 0;
}



/* 40948668 FUN_40948668 */

/* Boundary evidence: original MIPS .pdata 40948668..409487f7. Semantic name remains unreviewed. */

undefined4 * FUN_40948668(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  piVar1 = FUN_409519bc();
  if (param_3 == 1) {
    if ((*(uint *)(param_1 + 0x5c) & 1) != 0) {
      uVar5 = *(uint *)(piVar1[0xc] + 0x10c) & 1;
      goto joined_r0x40948744;
    }
  }
  else if ((param_3 == 2) && ((*(uint *)(param_1 + 0x5c) & 4) != 0)) {
    uVar5 = *(uint *)(piVar1[0xc] + 0x10c) & 4;
joined_r0x40948744:
    if (uVar5 != 0) {
      puVar2 = FUN_40951f98(param_1,param_3);
      if (puVar2 != (undefined4 *)0x0) {
        uVar4 = 0;
        if (param_2 != 0) {
          uVar4 = *(undefined4 *)(param_2 + 0xc);
        }
        iVar3 = (**(code **)((param_3 + -1) * 0x4c + piVar1[0xc] + 0x10))
                          (*(undefined4 *)(*(int *)(param_4 + 8) + 0x1c),uVar4,
                           __egl_get_image_ptr_implicit);
        puVar2[3] = iVar3;
        if (iVar3 != 0) {
          puVar2[10] = 0;
          if (param_3 == 1) {
            puVar2[10] = 2;
          }
          else if (param_3 == 2) {
            puVar2[10] = 0x16;
          }
          puVar2[2] = 0x30a0;
          return puVar2;
        }
        *(undefined4 *)(param_4 + 0x10) = 0x3003;
        FUN_409520e8((int)puVar2);
        return (undefined4 *)0x0;
      }
      if (param_4 == 0) {
        return (undefined4 *)0x0;
      }
      uVar4 = 0x3003;
      goto LAB_409486f0;
    }
  }
  if (param_4 == 0) {
    return (undefined4 *)0x0;
  }
  uVar4 = 0x3005;
LAB_409486f0:
  *(undefined4 *)(param_4 + 0x10) = uVar4;
  return (undefined4 *)0x0;
}



/* 409487f8 FUN_409487f8 */

/* Boundary evidence: original MIPS .pdata 409487f8..40948887. Semantic name remains unreviewed. */

void FUN_409487f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  FUN_40955b34();
  puVar1 = (undefined4 *)FUN_4094c9b4();
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_4094c80c(puVar1,&param_5);
    if (param_5 == 0x30a0) {
      (**(code **)(*(int *)(*(int *)(iVar2 + 0xc) + 0x18) * 0x4c + *(int *)(puVar1[2] + 0x30) + 0xc)
      )(param_1,param_2);
    }
    piVar3 = FUN_409519bc();
    if (piVar3 != (int *)0x0) {
      mali_sys_lock_unlock(piVar3[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x18);
}



/* 40948888 FUN_40948888 */

/* Boundary evidence: original MIPS .pdata 40948888..40948907. Semantic name remains unreviewed. */

undefined4 FUN_40948888(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  tagRECT tStack_20;
  
  GetClientRect((HWND)*param_1,&tStack_20);
  iVar1 = GetSystemMetrics(0);
  if (((tStack_20.right == iVar1) && (iVar1 = GetSystemMetrics(1), tStack_20.bottom == iVar1)) &&
     (uVar2 = GetWindowLongW((HWND)*param_1,-0x14), (uVar2 & 8) != 0)) {
    return 1;
  }
  return 0;
}



/* 40948918 FUN_40948918 */

/* Boundary evidence: original MIPS .pdata 40948918..40948947. Semantic name remains unreviewed. */

bool FUN_40948918(HWND param_1)

{
  BOOL BVar1;
  
  BVar1 = IsWindow(param_1);
  return BVar1 != 0;
}



/* 40948948 FUN_40948948 */

/* Boundary evidence: original MIPS .pdata 40948948..4094899f. Semantic name remains unreviewed. */

void FUN_40948948(undefined4 *param_1,int *param_2,int *param_3)

{
  tagRECT local_20;
  
  GetClientRect((HWND)*param_1,&local_20);
  *param_2 = local_20.right - local_20.left;
  *param_3 = local_20.bottom - local_20.top;
  return;
}



/* 409489a0 FUN_409489a0 */

/* Boundary evidence: original MIPS .pdata 409489a0..409489cb. Semantic name remains unreviewed. */

void FUN_409489a0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(param_3 + 0x104))(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 409489cc FUN_409489cc */

/* Boundary evidence: original MIPS .pdata 409489cc..409489f7. Semantic name remains unreviewed. */

void FUN_409489cc(void)

{
  NKDbgPrintfW(L"%s %d\r\n",L"src/egl/egl_platform_win32.c",0x8da);
  return;
}



/* 409489f8 FUN_409489f8 */

/* Boundary evidence: original MIPS .pdata 409489f8..40948a27. Semantic name remains unreviewed. */

undefined4 FUN_409489f8(void)

{
  NKDbgPrintfW(L"%s %d\r\n",L"src/egl/egl_platform_win32.c",0x8d0);
  return 0;
}



/* 40948a28 FUN_40948a28 */

/* Boundary evidence: original MIPS .pdata 40948a28..40948a53. Semantic name remains unreviewed. */

void FUN_40948a28(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(param_3 + 0x100))(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 40948a54 FUN_40948a54 */

/* Boundary evidence: original MIPS .pdata 40948a54..40948b9b. Semantic name remains unreviewed. */

void FUN_40948a54(int param_1,int *param_2)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_38 [8];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  int local_20;
  int local_1c;
  
  iVar6 = 0;
  iVar4 = -1;
  do {
    if (iVar4 != -1) break;
    mali_pixel_format_get_bpc
              (iVar6,auStack_24,&local_20,&local_1c,auStack_28,auStack_30,acStack_38 + 4);
    cVar3 = '\0';
    acStack_38[3] = 0;
    iVar4 = 2;
    piVar2 = &local_20;
    do {
      if (*piVar2 == 0) {
        pcVar1 = acStack_38 + iVar4;
        *pcVar1 = '\0';
      }
      else {
        pcVar1 = acStack_38 + iVar4;
        *pcVar1 = (char)piVar2[1] + cVar3;
      }
      cVar3 = *pcVar1 + cVar3;
      prefetch(piVar2 + -2,0);
      iVar4 = iVar4 + -1;
      piVar2 = piVar2 + -1;
    } while (-1 < iVar4);
    iVar5 = 3;
    piVar2 = &local_1c;
    do {
      if (((char)*piVar2 != *(char *)(param_1 + 0x58 + iVar5)) ||
         (acStack_38[iVar5] != *(char *)(iVar5 + param_1 + 0x5c))) {
        iVar4 = -1;
        break;
      }
      iVar5 = iVar5 + -1;
      piVar2 = piVar2 + -1;
      iVar4 = iVar6;
    } while (-1 < iVar5);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 9);
  *param_2 = iVar4;
  return;
}



/* 40948bac FUN_40948bac */

/* Boundary evidence: original MIPS .pdata 40948bac..40948c17. Semantic name remains unreviewed. */

undefined4 FUN_40948bac(HANDLE param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [4];
  int local_64;
  int local_60;
  
  iVar1 = GetObjectW(param_1,0x54,auStack_68);
  if ((iVar1 == 0x54) && (local_64 == *(int *)(param_2 + 0xbc))) {
    uVar2 = 0;
    if (local_60 == *(int *)(param_2 + 0xc0)) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40948c20 FUN_40948c20 */

/* Boundary evidence: original MIPS .pdata 40948c20..40948c53. Semantic name remains unreviewed. */

bool FUN_40948c20(HANDLE param_1)

{
  int iVar1;
  undefined1 auStack_60 [88];
  
  iVar1 = GetObjectW(param_1,0x54,auStack_60);
  return iVar1 != 0;
}



/* 40948c54 FUN_40948c54 */

/* Boundary evidence: original MIPS .pdata 40948c54..40948ca3. Semantic name remains unreviewed. */

void FUN_40948c54(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 auStack_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  
  iVar1 = GetObjectW(param_1,0x18,auStack_28);
  if (iVar1 != 0) {
    *param_2 = local_24;
    *param_3 = local_20;
  }
  return;
}



/* 40948cd0 FUN_40948cd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40948cd0..40948e9b. Semantic name remains unreviewed. */

void FUN_40948cd0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  HANDLE hDevice;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined *lpInBuffer;
  DWORD DStack00000020;
  
  FUN_40955a74();
  DStack00000020 = 0xffffffff;
  FUN_40948a54(param_3,(int *)&stack0x00000020);
  if (DStack00000020 != 0xffffffff) {
    lpInBuffer = &DAT_40958b40;
    piVar7 = (int *)(param_3 + 0x10);
    iVar6 = 0;
    piVar8 = piVar7;
    do {
      hDevice = DAT_40958afc;
      iVar1 = _DAT_00005b04;
      iVar3 = **(int **)(param_2 + 0xb8);
      if (iVar3 < 0) {
        iVar3 = iVar3 + 7;
      }
      iVar4 = *(int *)(param_2 + 0xc0);
      iVar5 = *(int *)(param_2 + 0xbc);
      *(undefined4 *)(lpInBuffer + 0x10) = 0;
      *(undefined4 *)(lpInBuffer + 0x14) = 2;
      iVar3 = (((iVar3 >> 3) * iVar4 * iVar5 + iVar1) - 1U & ~(iVar1 - 1U)) + 0x8000;
      *(int *)(lpInBuffer + 0xc) = iVar3;
      BVar2 = DeviceIoControl(hDevice,0x220404,lpInBuffer,0x20,(LPVOID)0x0,0,&stack0x00000020,
                              (LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        NKDbgPrintfW(L"Cannot get memory: %d size:%d\r\n",iVar6,iVar3);
      }
      piVar8[0xb] = 0;
      iVar3 = mali_mem_add_phys_mem
                        (param_4,*(undefined4 *)(lpInBuffer + 8),iVar3,
                         *(undefined4 *)(lpInBuffer + 4));
      piVar8[-4] = iVar3;
      if (iVar3 == 0) goto joined_r0x40948e68;
      iVar3 = mali_shared_mem_ref_alloc_existing_mem(iVar3);
      *piVar8 = iVar3;
      if (iVar3 == 0) goto joined_r0x40948e38;
      iVar6 = iVar6 + 1;
      lpInBuffer = lpInBuffer + 0x20;
      piVar8 = piVar8 + 1;
    } while (iVar6 < 4);
  }
LAB_40948e94:
                    /* WARNING: Subroutine does not return */
  FUN_40955aac(0x28);
joined_r0x40948e68:
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    mali_shared_mem_ref_owner_deref(*piVar7);
    *piVar7 = 0;
    piVar7[-4] = 0;
    piVar7 = piVar7 + 1;
  }
  goto LAB_40948e94;
joined_r0x40948e38:
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    mali_shared_mem_ref_owner_deref(*piVar7);
    *piVar7 = 0;
    piVar7[-4] = 0;
    piVar7 = piVar7 + 1;
  }
  goto LAB_40948e94;
}



/* 40948e9c FUN_40948e9c */

/* Boundary evidence: original MIPS .pdata 40948e9c..40948f23. Semantic name remains unreviewed. */

void FUN_40948e9c(void)

{
  BOOL BVar1;
  int iVar2;
  undefined *lpInBuffer;
  
  FUN_40955ae4();
  lpInBuffer = &DAT_40958b40;
  iVar2 = 0;
  do {
    BVar1 = DeviceIoControl(DAT_40958afc,0x220408,lpInBuffer,0x20,(LPVOID)0x0,0,
                            (LPDWORD)&stack0x00000020,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      NKDbgPrintfW(L"Cannot free memory: %d \r\n",iVar2);
    }
    iVar2 = iVar2 + 1;
    lpInBuffer = lpInBuffer + 0x20;
  } while (iVar2 < 4);
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x28);
}



/* 40948f24 FUN_40948f24 */

/* Boundary evidence: original MIPS .pdata 40948f24..40948f8f. Semantic name remains unreviewed. */

undefined4 FUN_40948f24(HDC param_1)

{
  DWORD DVar1;
  uint uVar2;
  
  if (param_1 != (HDC)0x0) {
    DVar1 = GetObjectType(param_1);
    if ((DVar1 != 3) && (DVar1 != 10)) {
      return 0;
    }
    uVar2 = GetDeviceCaps(param_1,0x26);
    if ((uVar2 & 1) == 0) {
      return 0;
    }
  }
  return 1;
}



/* 40948fa0 FUN_40948fa0 */

/* Boundary evidence: original MIPS .pdata 40948fa0..40949117. Semantic name remains unreviewed. */

undefined4 FUN_40948fa0(void)

{
  DWORD DVar1;
  LSTATUS LVar2;
  wchar_t *pwVar3;
  HKEY local_18;
  DWORD local_14;
  
  DAT_40958af8 = GetDC((HWND)0x0);
  if (DAT_40958af8 == (HDC)0xffffffff) {
    DVar1 = GetLastError();
    pwVar3 = L"Cannot open LCD1: %d\r\n";
  }
  else {
    DAT_40958afc = CreateFileW(L"MEM1:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (DAT_40958afc != (HANDLE)0xffffffff) {
      DAT_40958ae4 = 0;
      LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\Display\\AU13XXLCD\\Windows\\OpenGL",0,0,
                            &local_18);
      DVar1 = local_14;
      if (LVar2 == 0) {
        local_14 = 4;
        DVar1 = RegQueryValueExW(local_18,L"Index",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&DAT_40958284,
                                 &local_14);
      }
      if (DVar1 != 0) {
        DAT_40958284 = 2;
      }
      NKDbgPrintfW(L"EGL Using Au13XXLCD Overlay #%d\r\n",DAT_40958284);
      RegCloseKey(local_18);
      return 1;
    }
    DVar1 = GetLastError();
    pwVar3 = L"Cannot open MEM1: %d\r\n";
  }
  NKDbgPrintfW(pwVar3,DVar1);
  return 0;
}



/* 4094912c FUN_4094912c */

int FUN_4094912c(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
  }
  else {
    param_1 = param_1 >> 0x10;
  }
  if ((param_1 & 0xff00) == 0) {
    iVar1 = iVar1 + 8;
  }
  else {
    param_1 = param_1 >> 8;
  }
  return (uint)(byte)(&DAT_4094203c)[param_1] + iVar1;
}



/* 40949178 FUN_40949178 */

/* Boundary evidence: original MIPS .pdata 40949178..409491e7. Semantic name remains unreviewed. */

int FUN_40949178(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 40949208 FUN_40949208 */

/* Boundary evidence: original MIPS .pdata 40949208..40949223. Semantic name remains unreviewed. */

void FUN_40949208(int param_1)

{
  mali_sys_atomic_inc(param_1 + 4);
  return;
}



/* 40949224 FUN_40949224 */

/* Boundary evidence: original MIPS .pdata 40949224..40949247. Semantic name remains unreviewed. */

void FUN_40949224(void)

{
  CeGetThreadPriority(0x41);
  return;
}



/* 40949248 FUN_40949248 */

/* Boundary evidence: original MIPS .pdata 40949248..40949297. Semantic name remains unreviewed. */

undefined4 FUN_40949248(void)

{
  DAT_40958b04 = 1;
  EventModify(DAT_40958b08,3);
  WaitForSingleObject(DAT_40958b0c,0xffffffff);
  return DAT_40958b04;
}



/* 40949298 FUN_40949298 */

/* Boundary evidence: original MIPS .pdata 40949298..40949467. Semantic name remains unreviewed. */

void FUN_40949298(void)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  uint uStack00000050;
  int in_stack_00000078;
  
  FUN_40955b34();
  iVar1 = DAT_40958b14;
  uStack00000050 = DAT_4095827c;
  if ((in_stack_00000078 != 0) && (DAT_40958ae4 != 0)) {
    CeGetThreadPriority(0x41);
  }
  uStack00000018 = DAT_40958284;
  uStack0000001c = 0;
  uStack00000020 = (&DAT_40958b48)[*(int *)(iVar1 + 0x28) * 8];
  iVar4 = *(int *)(iVar1 + 0x28) + 1;
  *(int *)(iVar1 + 0x28) = iVar4;
  if (3 < iVar4) {
    *(undefined4 *)(iVar1 + 0x28) = 0;
  }
  ExtEscape(DAT_40958af8,0x229c54,0xc,(LPCSTR)&stack0x00000018,0,(LPSTR)0x0);
  if (DAT_40958b00 == 0) {
    ExtEscape(DAT_40958af8,0x229c44,4,(LPCSTR)&stack0x00000018,0,(LPSTR)0x0);
    DAT_40958b00 = 1;
  }
  if (DAT_409582c8 == 0xffffffff) {
    DAT_409582c8 = GetTickCount();
  }
  else {
    DVar2 = GetTickCount();
    if (DAT_409582c8 + 5000 <= DVar2) {
      DVar2 = GetTickCount();
      if (DAT_40958b18 == 0) {
        trap(0x1c00);
      }
      uVar3 = __ultofp((DVar2 - DAT_409582c8) / DAT_40958b18);
      uVar3 = __fpdiv(0x447a0000,uVar3);
      uVar5 = __fptodp(uVar3);
      sprintf(&stack0x00000028,"eglSwapBuffers: %f FPS\r\n",(int)uVar5,
              (int)((ulonglong)uVar5 >> 0x20));
      NKDbgPrintfW(&DAT_40944868,&stack0x00000028);
      DAT_409582c8 = GetTickCount();
      DAT_40958b18 = 0;
    }
  }
  DAT_40958b18 = DAT_40958b18 + 1;
  FUN_40945f88(uStack00000050);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x58);
}



/* 40949468 FUN_40949468 */

/* Boundary evidence: original MIPS .pdata 40949468..40949497. Semantic name remains unreviewed. */

bool FUN_40949468(HANDLE param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_40948bac(param_1,param_2);
  return iVar1 != 0;
}



/* 40949498 FUN_40949498 */

void FUN_40949498(undefined4 param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = DAT_40958b14;
  if ((param_2 != (uint *)0x0) && (DAT_40958b14 != 0)) {
    *param_2 = (uint)*(byte *)(DAT_40958b14 + 0x59);
    param_2[1] = (uint)*(byte *)(iVar1 + 0x5a);
    param_2[2] = (uint)*(byte *)(iVar1 + 0x5b);
    param_2[3] = (uint)*(byte *)(iVar1 + 0x5d);
    param_2[4] = (uint)*(byte *)(iVar1 + 0x5e);
    param_2[5] = (uint)*(byte *)(iVar1 + 0x5f);
  }
  return;
}



/* 409494e8 FUN_409494e8 */

/* Boundary evidence: original MIPS .pdata 409494e8..4094951f. Semantic name remains unreviewed. */

int FUN_409494e8(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0x20;
  }
  else {
    iVar1 = FUN_4094912c(-param_1 & param_1);
    iVar1 = 0x1f - iVar1;
  }
  return iVar1;
}



/* 40949520 FUN_40949520 */

/* Boundary evidence: original MIPS .pdata 40949520..40949567. Semantic name remains unreviewed. */

void FUN_40949520(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_40955b34();
  uVar1 = mali_pixel_layout_to_texel_layout(0);
  uVar2 = mali_pixel_to_texel_format(param_2);
  *param_1 = param_2;
  param_1[1] = uVar2;
  param_1[2] = 0;
  param_1[3] = uVar1;
  param_1[4] = 0;
                    /* WARNING: Subroutine does not return */
  param_1[5] = 0;
  FUN_40955b54(0x10);
}



/* 40949568 FUN_40949568 */

/* Boundary evidence: original MIPS .pdata 40949568..409496a7. Semantic name remains unreviewed. */

void FUN_40949568(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 in_stack_00000018;
  
  FUN_40955b34();
  FUN_409519bc();
  if (param_1[0x29] == 1) {
    if ((HWND)*param_1 != (HWND)0x0) {
      SendMessageW((HWND)*param_1,0x10,0,0);
    }
  }
  else {
    in_stack_00000018 = DAT_40958284;
    ExtEscape(DAT_40958af8,0x229c50,0x20,(LPCSTR)&stack0x00000018,0,(LPSTR)0x0);
    DAT_40958b00 = 0;
    ExtEscape(DAT_40958af8,0x229c48,4,(LPCSTR)&stack0x00000018,0,(LPSTR)0x0);
  }
  iVar2 = param_1[0x42];
  if (iVar2 != 0) {
    if (param_1[2] != 0) {
      FUN_4094f464(param_1[2]);
    }
    param_1[2] = 0;
    puVar1 = DAT_40958b14;
    if (((*(int *)(iVar2 + 0x74) == 3) || (*(int *)(iVar2 + 0x74) == 2)) &&
       (DAT_40958b14 != (undefined4 *)0x0)) {
      FUN_40948e9c();
      *(undefined4 *)(iVar2 + 0x74) = 0;
      if (puVar1[4] != 0) {
        mali_shared_mem_ref_owner_deref();
        *puVar1 = 0;
        puVar1[4] = 0;
      }
      if (puVar1[5] != 0) {
        mali_shared_mem_ref_owner_deref();
        puVar1[1] = 0;
        puVar1[5] = 0;
      }
    }
    mali_sys_free(iVar2);
    param_1[0x42] = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x38);
}



/* 409496a8 FUN_409496a8 */

/* Boundary evidence: original MIPS .pdata 409496a8..4094972b. Semantic name remains unreviewed. */

void FUN_409496a8(void)

{
  int iVar1;
  
  FUN_40955b34();
  FUN_409519bc();
  iVar1 = DAT_40958b14;
  if (DAT_40958b14 != 0) {
    DAT_40958b04 = 0;
    EventModify(DAT_40958b08,3);
    mali_osu_wait_for_thread(DAT_40958b10,0);
    DAT_40958b10 = 0;
    CloseHandle(DAT_40958b08);
    CloseHandle(DAT_40958b0c);
    DAT_40958b08 = (HANDLE)0x0;
    DAT_40958b0c = (HANDLE)0x0;
    mali_sys_free(iVar1);
    DAT_40958b14 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094972c FUN_4094972c */

/* Boundary evidence: original MIPS .pdata 4094972c..40949837. Semantic name remains unreviewed. */

int FUN_4094972c(int param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
                undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_40 [2];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_40[0] = -1;
  FUN_40948a54(param_2,local_40);
  local_38 = local_40[0];
  if (local_40[0] != -1) {
    uVar1 = mali_pixel_layout_to_texel_layout(0);
    local_34 = mali_pixel_to_texel_format(local_38);
    piVar3 = (int *)((param_1 + 4) * 4 + param_2);
    iVar2 = *piVar3;
    local_30 = 0;
    local_28 = 0;
    local_24 = 0;
    if (iVar2 != 0) {
      local_2c = uVar1;
      iVar2 = mali_surface_alloc_ref(param_3,param_4,param_5,&local_38,iVar2,param_6,param_7);
      if (iVar2 == 0) {
        return 0;
      }
      mali_sys_atomic_inc(*piVar3 + 4);
      *(undefined4 *)(iVar2 + 0x3c) = 1;
      return iVar2;
    }
  }
  return 0;
}



/* 40949838 FUN_40949838 */

/* Boundary evidence: original MIPS .pdata 40949838..409498f3. Semantic name remains unreviewed. */

bool FUN_40949838(uint param_1,undefined1 *param_2,undefined1 *param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    iVar2 = FUN_4094912c(-param_1 & param_1);
    uVar3 = 0x1f - iVar2;
    if (uVar3 != 0x20) goto LAB_4094988c;
  }
  uVar3 = 0;
LAB_4094988c:
  iVar2 = FUN_4094912c(param_1);
  uVar4 = (0x20 - (uVar3 & 0xff)) - iVar2;
  bVar1 = param_1 == (1 << (uVar4 & 0x1f)) + -1 << (uVar3 & 0x1f);
  if (bVar1) {
    *param_2 = (char)uVar4;
    *param_3 = (char)uVar3;
  }
  return bVar1;
}



/* 409498f4 FUN_409498f4 */

/* Boundary evidence: original MIPS .pdata 409498f4..40949c33. Semantic name remains unreviewed. */

void FUN_409498f4(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int in_stack_00000020;
  uint in_stack_00000024;
  int in_stack_00000030;
  undefined4 in_stack_00000040;
  uint in_stack_00000044;
  uint in_stack_00000048;
  uint in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  
  FUN_40955a74();
  memset(&stack0x00000030,0,0x10);
  GetWindowRect((HWND)*param_1,(LPRECT)&stack0x00000020);
  if (in_stack_00000020 < 0) {
    in_stack_00000020 = 0;
  }
  if ((int)in_stack_00000024 < 0) {
    in_stack_00000024 = 0;
  }
  FUN_409519bc();
  iVar1 = mali_sys_malloc(0x78);
  if (iVar1 == 0) goto LAB_40949c28;
  param_1[0x42] = iVar1;
  if (param_1[0x29] != 0) {
    SetWindowLongW((HWND)*param_1,0,(LONG)param_1);
  }
  *(undefined4 *)(iVar1 + 0x74) = 0;
  pcVar2 = (char *)mali_sys_config_string_get("MALI_SINGLEBUFFER");
  if (pcVar2 != (char *)0x0) {
    if (*pcVar2 != '0') {
      param_1[0x39] = 0x3085;
    }
    mali_sys_config_string_release(pcVar2);
  }
  iVar7 = 4;
  iVar3 = FUN_40948cd0(4,(int)param_1,param_3,param_2);
  if (iVar3 == 1) {
    iVar3 = 0;
    piVar8 = &stack0x00000030;
    puVar10 = (undefined4 *)(param_3 + 0x3c);
    do {
      iVar4 = FUN_4094972c(iVar3,param_3,(short)param_1[0x2f],(short)param_1[0x30],
                           (short)*(undefined4 *)(param_3 + 0x4c),*puVar10,param_2);
      iVar3 = iVar3 + 1;
      *piVar8 = iVar4;
      piVar8 = piVar8 + 1;
      puVar10 = puVar10 + 1;
    } while (iVar3 < 4);
    if (iVar3 == 4) {
      param_1[0x40] = FUN_40949298;
      param_1[4] = 1;
      *(undefined4 *)(iVar1 + 0x74) = 3;
      goto LAB_40949a50;
    }
  }
  else {
LAB_40949a50:
    param_1[0x39] = 0x3084;
    iVar3 = FUN_4094e7ac(param_2,param_1[0x2e],(int)&stack0x00000030);
    param_1[2] = iVar3;
    if (iVar3 != 0) {
      uVar5 = mali_frame_builder_get_attachment(iVar3,0);
      *(undefined2 *)((int)param_1 + 0x72) = 4;
      puVar9 = &stack0x00000030;
      puVar10 = param_1 + 8;
      do {
        mali_render_attachment_set_target(uVar5,0,*puVar9,0);
        uVar6 = mali_render_attachment_get_target(uVar5,0,0);
        iVar7 = iVar7 + -1;
        puVar10[-3] = uVar6;
        puVar10[-2] = param_1;
        *(undefined2 *)puVar10 = 0;
        puVar10[-1] = 0;
        puVar10 = puVar10 + 5;
        puVar9 = puVar9 + 1;
      } while (iVar7 != 0);
      mali_render_attachment_set_target(uVar5,0,in_stack_00000030,0);
      *(undefined4 *)(iVar1 + 0x6c) = 0;
      *(undefined4 *)(iVar1 + 0x70) = 1;
      in_stack_00000048 = 0x18000000;
      if (((int *)param_1[0x2e])[0x20] == 0) {
        in_stack_00000048 = 0xc000000;
      }
      in_stack_00000040 = DAT_40958284;
      in_stack_00000054 = 0;
      in_stack_00000044 = (in_stack_00000020 << 0xb | in_stack_00000024) << 10 | 0x1ec;
      in_stack_00000048 = (param_1[0x2f] - 1 | 0x800) << 0xb | param_1[0x30] - 1 | in_stack_00000048
      ;
      iVar1 = *(int *)param_1[0x2e];
      if (iVar1 < 0) {
        iVar1 = iVar1 + 7;
      }
      in_stack_0000004c = ((iVar1 >> 3) * param_1[0x2f] | 0x30000U) << 8;
      iVar1 = FUN_40948888(param_1);
      if (iVar1 == 1) {
        in_stack_0000004c = in_stack_0000004c & 0xfcffffff;
      }
      else {
        in_stack_0000004c = in_stack_0000004c | 0x3000000;
      }
      in_stack_00000058 = *param_1;
      in_stack_00000050 = 0;
      ExtEscape(DAT_40958af8,0x229c4c,0x20,(LPCSTR)&stack0x00000040,0,(LPSTR)0x0);
      goto LAB_40949c28;
    }
  }
  piVar8 = &stack0x00000030;
  do {
    if (*piVar8 != 0) {
      FUN_40949178(*piVar8);
      *piVar8 = 0;
    }
    iVar7 = iVar7 + -1;
    piVar8 = piVar8 + 1;
  } while (iVar7 != 0);
  FUN_40948e9c();
  mali_sys_free(param_1[0x42]);
  param_1[0x42] = 0;
LAB_40949c28:
                    /* WARNING: Subroutine does not return */
  FUN_40955aac(0x60);
}



/* 40949c34 FUN_40949c34 */

/* Boundary evidence: original MIPS .pdata 40949c34..40949d6b. Semantic name remains unreviewed. */

undefined4 FUN_40949c34(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (DAT_40958b14 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)mali_sys_malloc(0x60);
    if (puVar1 != (undefined4 *)0x0) {
      mali_sys_memset(puVar1,0,0x60);
      puVar1[8] = 0;
      puVar1[9] = 1;
      puVar1[10] = 0;
      FUN_40949838(DAT_409582b8,(undefined1 *)((int)puVar1 + 0x59),
                   (undefined1 *)((int)puVar1 + 0x5d));
      FUN_40949838(DAT_409582bc,(undefined1 *)((int)puVar1 + 0x5a),
                   (undefined1 *)((int)puVar1 + 0x5e));
      FUN_40949838(DAT_409582c0,(undefined1 *)((int)puVar1 + 0x5b),
                   (undefined1 *)((int)puVar1 + 0x5f));
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      DAT_40958b14 = puVar1;
      DAT_40958b08 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      DAT_40958b0c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if ((DAT_40958b08 != (HANDLE)0x0) && (DAT_40958b0c != (HANDLE)0x0)) {
        return 1;
      }
      mali_sys_free(puVar1);
      DAT_40958b14 = (undefined4 *)0x0;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 40949d6c FUN_40949d6c */

/* Boundary evidence: original MIPS .pdata 40949d6c..40949fc7. Semantic name remains unreviewed. */

int FUN_40949d6c(undefined1 *param_1,HANDLE param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 auStack_88 [18];
  ushort local_76;
  ushort local_62;
  int local_60;
  int local_50;
  uint local_40 [3];
  undefined4 local_34;
  undefined1 auStack_31 [9];
  uint local_28;
  uint local_24;
  
  local_24 = DAT_4095827c;
  iVar2 = GetObjectW(param_2,0x58,auStack_88);
  if (iVar2 == 0x18) {
    if ((((local_76 == 0) || (local_76 < 3)) || (local_76 == 4)) || (local_76 == 8))
    goto LAB_40949f94;
    if (local_76 == 0x10) {
LAB_40949e8c:
      uVar3 = 5;
      param_1[5] = 10;
      *(undefined4 *)(param_1 + 8) = 0x10;
      goto LAB_40949e54;
    }
    if (local_76 != 0x18) {
      if (local_76 != 0x20) goto LAB_40949f94;
      goto LAB_40949e4c;
    }
LAB_40949e84:
    *(undefined4 *)(param_1 + 8) = 0x18;
  }
  else {
    uVar6 = 0;
    if (iVar2 != 0x54) {
      if (iVar2 != 0x58) goto LAB_40949f94;
      if ((local_60 == 6) && (uVar6 = local_34, local_50 == 4)) {
        local_50 = 3;
      }
    }
    local_28 = (uint)local_62;
    if ((local_28 < 9) || ((local_50 != 3 && (local_50 != 0)))) {
LAB_40949f94:
      FUN_40945f88(local_24);
      return 0;
    }
    if (local_60 != 0) {
      if ((local_60 == 6) || (local_60 == 3)) {
        puVar5 = local_40;
        iVar2 = 3;
        do {
          iVar4 = iVar2;
          bVar1 = FUN_40949838(*puVar5,(undefined1 *)((int)register0x00000074 + -0x31) + iVar4 + 1,
                               (undefined1 *)((int)register0x00000074 + -0x31) + iVar4 + 5);
          iVar2 = CONCAT31(extraout_var,bVar1);
          if (iVar2 != 1) goto LAB_40949f10;
          puVar5 = puVar5 + -1;
          iVar2 = iVar4 + -1;
        } while (0 < iVar4 + -1);
        bVar1 = FUN_40949838(uVar6,(undefined1 *)((int)register0x00000074 + -0x31) + iVar4,
                             (undefined1 *)((int)register0x00000074 + -0x31) + iVar4 + 4);
        iVar2 = CONCAT31(extraout_var_00,bVar1);
        if (iVar2 == 1) {
          mali_sys_memcpy(param_1,(undefined1 *)((int)register0x00000074 + -0x31) + 1,0xc);
          FUN_40945f88(local_24);
          return 1;
        }
LAB_40949f10:
        FUN_40945f88(local_24);
        return iVar2;
      }
      goto LAB_40949f94;
    }
    if (local_28 == 0x10) goto LAB_40949e8c;
    if (local_28 == 0x18) goto LAB_40949e84;
    if (local_28 != 0x20) goto LAB_40949f94;
LAB_40949e4c:
    *(undefined4 *)(param_1 + 8) = 0x20;
  }
  uVar3 = 8;
  param_1[5] = 0x10;
LAB_40949e54:
  *param_1 = 0;
  param_1[1] = uVar3;
  param_1[2] = uVar3;
  param_1[3] = uVar3;
  param_1[4] = 0;
  param_1[6] = uVar3;
  param_1[7] = 0;
  FUN_40945f88(local_24);
  return 1;
}



/* 40949fc8 FUN_40949fc8 */

/* Boundary evidence: original MIPS .pdata 40949fc8..4094a0a7. Semantic name remains unreviewed. */

undefined4 FUN_40949fc8(HANDLE param_1,int *param_2)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte local_20 [12];
  uint local_14;
  
  local_14 = DAT_4095827c;
  iVar3 = 0;
  iVar1 = FUN_40949d6c(local_20,param_1);
  if (iVar1 != 0) {
    iVar1 = 3;
    do {
      pbVar2 = local_20 + iVar1;
      iVar1 = iVar1 + -1;
      iVar3 = (uint)*pbVar2 + iVar3;
    } while (-1 < iVar1);
    if ((((iVar3 == *param_2) && ((uint)local_20[1] == param_2[1])) &&
        ((uint)local_20[2] == param_2[2])) &&
       ((((uint)local_20[3] == param_2[3] && ((uint)local_20[0] == param_2[5])) && (param_2[4] == 0)
        ))) {
      FUN_40945f88(local_14);
      return 1;
    }
  }
  FUN_40945f88(local_14);
  return 0;
}



/* 4094a0a8 FUN_4094a0a8 */

/* Boundary evidence: original MIPS .pdata 4094a0a8..4094a10f. Semantic name remains unreviewed. */

undefined4 FUN_4094a0a8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_40958b14 == 0) {
    uVar1 = 0;
  }
  else {
    if ((-1 < (int)param_1[3]) && ((int)param_1[3] < 3)) {
      uVar1 = FUN_409498f4(param_1,param_3,DAT_40958b14);
    }
    param_1[0x41] = FUN_409489cc;
  }
  return uVar1;
}



/* 4094a110 FUN_4094a110 */

/* Boundary evidence: original MIPS .pdata 4094a110..4094a14b. Semantic name remains unreviewed. */

void FUN_4094a110(void)

{
  FUN_409519bc();
  FUN_40949c34();
  return;
}



/* 4094a14c __egl_build_info */

char * __egl_build_info(void)

{
                    /* 0xa14c  1  __egl_build_info */
  return "egl:  ";
}



/* 4094a158 mali_egl_image_get_error */

/* Boundary evidence: original MIPS .pdata 4094a158..4094a173. Semantic name remains unreviewed. */

void mali_egl_image_get_error(void)

{
                    /* 0xa158  43  mali_egl_image_get_error */
  mali_sys_thread_key_get_data(6);
  return;
}



/* 4094a174 FUN_4094a174 */

/* Boundary evidence: original MIPS .pdata 4094a174..4094a193. Semantic name remains unreviewed. */

void FUN_4094a174(undefined4 param_1)

{
  mali_sys_thread_key_set_data(6,param_1);
  return;
}



/* 4094a19c FUN_4094a19c */

/* Boundary evidence: original MIPS .pdata 4094a19c..4094a2ef. Semantic name remains unreviewed. */

int FUN_4094a19c(undefined4 param_1,int param_2,int *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  bVar1 = false;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 4;
  if (param_2 != 0) {
    piVar4 = (int *)(param_2 + 4);
    do {
      iVar3 = piVar4[-1];
      if (iVar3 == 0) {
LAB_4094a20c:
        bVar1 = true;
      }
      else if (iVar3 == 0xfa) {
        iVar3 = *piVar4;
        if ((iVar3 < 0) || (0xc < iVar3)) {
LAB_4094a2dc:
          uVar2 = 0x4006;
LAB_4094a2e0:
          mali_sys_thread_key_set_data(6,uVar2);
          return 0;
        }
        *param_3 = iVar3;
      }
      else if (iVar3 == 0xfb) {
        iVar3 = *piVar4;
        if ((iVar3 < 0x100) || (0x104 < iVar3)) goto LAB_4094a2dc;
        param_3[1] = iVar3 + -0x100;
      }
      else {
        if (iVar3 != 0xfc) {
          if (iVar3 != 0x3038) {
            uVar2 = 0x4008;
            goto LAB_4094a2e0;
          }
          goto LAB_4094a20c;
        }
        iVar3 = *piVar4;
        if (iVar3 == 1) {
          param_3[2] = 1;
        }
        else if (iVar3 == 2) {
          param_3[2] = 2;
        }
        else {
          if (iVar3 != 4) goto LAB_4094a2dc;
          param_3[2] = 4;
        }
      }
      prefetch(piVar4 + 3,0);
      piVar4 = piVar4 + 2;
    } while (!bVar1);
  }
  iVar3 = mali_image_get_buffer(param_1,param_3[1],*param_3,1);
  if (iVar3 == 0) {
    mali_sys_thread_key_set_data(6,0x4005);
  }
  return iVar3;
}



/* 4094a2f0 FUN_4094a2f0 */

/* Boundary evidence: original MIPS .pdata 4094a2f0..4094a36f. Semantic name remains unreviewed. */

undefined4 FUN_4094a2f0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_4094bfcc(param_1,0,5);
  if ((uVar1 == 0) || ((uVar1 | 0x10000000) == 0)) {
    uVar3 = 0x4009;
  }
  else {
    iVar2 = mali_sys_lock_try_lock(*(undefined4 *)(param_1 + 0x1c));
    if (iVar2 != 0) {
      return 1;
    }
    FUN_4094acf4(param_1);
    uVar3 = 0x4003;
  }
  mali_sys_thread_key_set_data(6,uVar3);
  return 0;
}



/* 4094a370 mali_egl_image_wait_sync */

/* WARNING: Removing unreachable block (ram,0x4094a3fc) */
/* Boundary evidence: original MIPS .pdata 4094a370..4094a443. Semantic name remains unreviewed. */

void mali_egl_image_wait_sync(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  
                    /* 0xa370  53  mali_egl_image_wait_sync */
  FUN_40955ae4();
  bVar1 = true;
  mali_sys_thread_key_set_data(6,0x4001);
  iVar2 = FUN_4094a2f0(param_1);
  if (iVar2 != 0) {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x10);
    mali_sys_get_time_usec();
LAB_4094a3c0:
    do {
      iVar2 = mali_surface_lock_sync_handle(uVar3);
      if (iVar2 == 1) {
        mali_surface_unlock_sync_handle(uVar3);
        goto LAB_4094a438;
      }
      mali_sys_yield();
      uVar4 = mali_sys_get_time_usec();
      if (param_2 != 0) {
        if (uVar4 <= (ulonglong)(longlong)(int)param_2) {
          bVar1 = true;
          goto LAB_4094a3c0;
        }
        bVar1 = false;
      }
    } while (bVar1);
    mali_sys_thread_key_set_data(6,0x4010);
  }
LAB_4094a438:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x10);
}



/* 4094a444 mali_egl_image_set_sync */

/* Boundary evidence: original MIPS .pdata 4094a444..4094a4b3. Semantic name remains unreviewed. */

undefined4 mali_egl_image_set_sync(int param_1)

{
  int iVar1;
  
                    /* 0xa444  50  mali_egl_image_set_sync */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if (iVar1 != 0) {
    iVar1 = mali_surface_lock_sync_handle(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x10));
    if (iVar1 != 0) {
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4003);
  }
  return 0;
}



/* 4094a4b4 mali_egl_image_create_sync */

/* Boundary evidence: original MIPS .pdata 4094a4b4..4094a4fb. Semantic name remains unreviewed. */

bool mali_egl_image_create_sync(int param_1)

{
  int iVar1;
  
                    /* 0xa4b4  39  mali_egl_image_create_sync */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  return iVar1 != 0;
}



/* 4094a4fc mali_egl_image_get_buffer_layout */

/* Boundary evidence: original MIPS .pdata 4094a4fc..4094a5b3. Semantic name remains unreviewed. */

void mali_egl_image_get_buffer_layout(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
                    /* 0xa4fc  41  mali_egl_image_get_buffer_layout */
  FUN_40955b34();
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4094a19c(*(undefined4 *)(param_1 + 0x20),param_2,(int *)&stack0x00000010),
     iVar1 != 0)) {
    if (param_3 == (undefined4 *)0x0) {
      mali_sys_thread_key_set_data(6,0x4008);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x1c);
      if (iVar1 == 0) {
        *param_3 = 0x110;
      }
      else if (iVar1 == 1) {
        *param_3 = 0x111;
      }
      else if (iVar1 == 2) {
        *param_3 = 0x112;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x20);
}



/* 4094a5b4 mali_egl_image_get_buffer_height */

/* Boundary evidence: original MIPS .pdata 4094a5b4..4094a637. Semantic name remains unreviewed. */

void mali_egl_image_get_buffer_height(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  
                    /* 0xa5b4  40  mali_egl_image_get_buffer_height */
  FUN_40955b34();
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4094a19c(*(undefined4 *)(param_1 + 0x20),param_2,(int *)&stack0x00000010),
     iVar1 != 0)) {
    if (param_3 == (uint *)0x0) {
      mali_sys_thread_key_set_data(6,0x4008);
    }
    else {
      *param_3 = (uint)*(ushort *)(iVar1 + 0xe);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x20);
}



/* 4094a638 mali_egl_image_get_buffer_width */

/* Boundary evidence: original MIPS .pdata 4094a638..4094a6bb. Semantic name remains unreviewed. */

void mali_egl_image_get_buffer_width(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  
                    /* 0xa638  42  mali_egl_image_get_buffer_width */
  FUN_40955b34();
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4094a19c(*(undefined4 *)(param_1 + 0x20),param_2,(int *)&stack0x00000010),
     iVar1 != 0)) {
    if (param_3 == (uint *)0x0) {
      mali_sys_thread_key_set_data(6,0x4008);
    }
    else {
      *param_3 = (uint)*(ushort *)(iVar1 + 0xc);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x20);
}



/* 4094a6bc mali_egl_image_unmap_buffer */

/* Boundary evidence: original MIPS .pdata 4094a6bc..4094a783. Semantic name remains unreviewed. */

undefined4 mali_egl_image_unmap_buffer(int param_1,int param_2)

{
  int iVar1;
  undefined2 local_20 [2];
  undefined2 local_1c;
  
                    /* 0xa6bc  52  mali_egl_image_unmap_buffer */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4094a19c(*(undefined4 *)(param_1 + 0x20),param_2,(int *)local_20), iVar1 != 0)) {
    iVar1 = mali_image_unlock(*(undefined4 *)(param_1 + 0x20),local_1c,local_20[0],0,0,
                              *(undefined2 *)(iVar1 + 0xc),*(undefined2 *)(iVar1 + 0xe),
                              *(undefined4 *)(param_1 + 0x24));
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4004);
  }
  return 0;
}



/* 4094a784 mali_egl_image_map_buffer */

/* Boundary evidence: original MIPS .pdata 4094a784..4094a8a3. Semantic name remains unreviewed. */

void mali_egl_image_map_buffer(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iStack00000030;
  undefined4 uStack00000034;
  undefined2 in_stack_00000038;
  undefined2 in_stack_0000003c;
  undefined4 in_stack_00000040;
  
                    /* 0xa784  48  mali_egl_image_map_buffer */
  FUN_40955b34();
  iStack00000030 = 0;
  uStack00000034 = 0;
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if ((iVar1 == 0) ||
     (iVar1 = FUN_4094a19c(*(undefined4 *)(param_1 + 0x20),param_2,(int *)&stack0x00000038),
     iVar1 == 0)) goto LAB_4094a89c;
  iVar1 = mali_image_lock(*(undefined4 *)(param_1 + 0x20),in_stack_00000040,in_stack_0000003c,
                          in_stack_00000038);
  if (iVar1 == 2) {
    uVar2 = 0x4005;
LAB_4094a880:
    mali_sys_thread_key_set_data(6,uVar2);
  }
  else if (2 < iVar1) {
    if (iVar1 < 5) {
      uVar2 = 0x4004;
    }
    else if (iVar1 == 5) {
      uVar2 = 0x4007;
    }
    else {
      if (iVar1 != 6) goto LAB_4094a888;
      uVar2 = 0x4008;
    }
    goto LAB_4094a880;
  }
LAB_4094a888:
  if (iStack00000030 != 0) {
    *(int *)(param_1 + 0x24) = iStack00000030;
  }
LAB_4094a89c:
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x48);
}



/* 4094a8a4 mali_egl_image_get_format */

/* Boundary evidence: original MIPS .pdata 4094a8a4..4094a937. Semantic name remains unreviewed. */

undefined4 mali_egl_image_get_format(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0xa8a4  44  mali_egl_image_get_format */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x20) + 0x108);
      if (puVar2 == (undefined4 *)0x0) {
        *param_2 = 0x3038;
      }
      else {
        *param_2 = *puVar2;
      }
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4008);
  }
  return 0;
}



/* 4094a938 mali_egl_image_get_height */

/* Boundary evidence: original MIPS .pdata 4094a938..4094a9b3. Semantic name remains unreviewed. */

undefined4 mali_egl_image_get_height(int param_1,undefined4 *param_2)

{
  int iVar1;
  
                    /* 0xa938  45  mali_egl_image_get_height */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4008);
  }
  return 0;
}



/* 4094a9b4 mali_egl_image_get_width */

/* Boundary evidence: original MIPS .pdata 4094a9b4..4094aa2f. Semantic name remains unreviewed. */

undefined4 mali_egl_image_get_width(int param_1,undefined4 *param_2)

{
  int iVar1;
  
                    /* 0xa9b4  46  mali_egl_image_get_width */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = **(undefined4 **)(param_1 + 0x20);
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4008);
  }
  return 0;
}



/* 4094aa30 mali_egl_image_set_data */

/* Boundary evidence: original MIPS .pdata 4094aa30..4094ab17. Semantic name remains unreviewed. */

undefined4 mali_egl_image_set_data(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_28;
  undefined4 local_24;
  
                    /* 0xaa30  49  mali_egl_image_set_data */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094a2f0(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4094a19c(*(undefined4 *)(param_1 + 0x20),param_2,&local_28), iVar1 != 0)) {
    iVar1 = mali_image_set_data(*(undefined4 *)(param_1 + 0x20),local_24,local_28,param_3);
    if (iVar1 == 0) {
      return 1;
    }
    if ((iVar1 == 1) || (iVar1 == 2)) {
      uVar2 = 0x4005;
    }
    else if (iVar1 == 5) {
      uVar2 = 0x4007;
    }
    else {
      if (iVar1 != 6) {
        return 0;
      }
      uVar2 = 0x4008;
    }
    mali_sys_thread_key_set_data(6,uVar2);
  }
  return 0;
}



/* 4094ab18 mali_egl_image_unlock_ptr */

/* Boundary evidence: original MIPS .pdata 4094ab18..4094abaf. Semantic name remains unreviewed. */

undefined4
mali_egl_image_unlock_ptr(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  
                    /* 0xab18  51  mali_egl_image_unlock_ptr */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar2 = FUN_4094b90c(param_1);
  if (iVar2 == 0) {
    uVar3 = 0x4002;
  }
  else {
    mali_image_unlock_all_sessions(*(undefined4 *)(iVar2 + 0x20));
    *(undefined4 *)(iVar2 + 0x24) = 0xffffffff;
    bVar1 = FUN_4094acf4(iVar2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if (*(int *)(iVar2 + 0x14) == 0) {
        FUN_4094afc8(iVar2,0,param_3,param_4,unaff_s0,unaff_retaddr);
      }
      return 1;
    }
    uVar3 = 0x4003;
  }
  mali_sys_thread_key_set_data(6,uVar3);
  return 0;
}



/* 4094abb0 mali_egl_image_lock_ptr */

/* Boundary evidence: original MIPS .pdata 4094abb0..4094ac7f. Semantic name remains unreviewed. */

int mali_egl_image_lock_ptr(uint param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* 0xabb0  47  mali_egl_image_lock_ptr */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    iVar1 = FUN_4094b90c(param_1);
    if (iVar1 != 0) {
      iVar3 = mali_sys_lock_try_lock(*(undefined4 *)(iVar1 + 0x1c));
      if (iVar3 == 0) {
        piVar2 = FUN_409519bc();
        if (piVar2 == (int *)0x0) {
          return iVar1;
        }
        mali_sys_lock_unlock(piVar2[5]);
        return iVar1;
      }
      piVar2 = FUN_409519bc();
      if (piVar2 != (int *)0x0) {
        mali_sys_lock_unlock(piVar2[5]);
      }
      uVar4 = 0x4003;
      goto LAB_4094abe0;
    }
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  uVar4 = 0x4002;
LAB_4094abe0:
  mali_sys_thread_key_set_data(6,uVar4);
  return 0;
}



/* 4094ac80 FUN_4094ac80 */

/* Boundary evidence: original MIPS .pdata 4094ac80..4094acf3. Semantic name remains unreviewed. */

undefined4 * FUN_4094ac80(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 1;
    *puVar1 = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0xffffffff;
    iVar2 = mali_sys_lock_create();
    puVar1[7] = iVar2;
    if (iVar2 != 0) {
      return puVar1;
    }
    mali_sys_free(puVar1);
  }
  return (undefined4 *)0x0;
}



/* 4094acf4 FUN_4094acf4 */

/* Boundary evidence: original MIPS .pdata 4094acf4..4094ad3b. Semantic name remains unreviewed. */

bool FUN_4094acf4(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_lock_try_lock(*(undefined4 *)(param_1 + 0x1c));
  mali_sys_lock_unlock(*(undefined4 *)(param_1 + 0x1c));
  return iVar1 != 0;
}



/* 4094ad3c FUN_4094ad3c */

/* Boundary evidence: original MIPS .pdata 4094ad3c..4094ad6b. Semantic name remains unreviewed. */

bool FUN_4094ad3c(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_lock_try_lock(*(undefined4 *)(param_1 + 0x1c));
  return iVar1 == 0;
}



/* 4094ad6c FUN_4094ad6c */

/* Boundary evidence: original MIPS .pdata 4094ad6c..4094ae0f. Semantic name remains unreviewed. */

bool FUN_4094ad6c(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_20 [8];
  
  piVar1 = FUN_409519bc();
  iVar2 = piVar1[0x12];
  __mali_named_list_lock(iVar2);
  piVar1 = (int *)__mali_named_list_iterate_begin(iVar2,auStack_20);
  while ((piVar1 != (int *)0x0 && ((param_4 != *piVar1 || (param_3 != piVar1[1]))))) {
    piVar1 = (int *)__mali_named_list_iterate_next(iVar2,auStack_20);
  }
  __mali_named_list_unlock(iVar2);
  return piVar1 != (int *)0x0;
}



/* 4094ae10 __egl_get_image_ptr_implicit */

/* Boundary evidence: original MIPS .pdata 4094ae10..4094ae43. Semantic name remains unreviewed. */

int __egl_get_image_ptr_implicit(uint param_1)

{
  int iVar1;
  
                    /* 0xae10  2  __egl_get_image_ptr_implicit */
  iVar1 = FUN_4094b90c(param_1);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x14) == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4094ae44 FUN_4094ae44 */

/* Boundary evidence: original MIPS .pdata 4094ae44..4094aeaf. Semantic name remains unreviewed. */

void FUN_4094ae44(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    mali_image_release();
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  FUN_4094bd58(param_1,0,5,param_4,unaff_s0,unaff_retaddr);
  if (*(int *)(param_1 + 0x18) != 0) {
    mali_sys_free();
  }
  mali_sys_lock_destroy(*(undefined4 *)(param_1 + 0x1c));
  mali_sys_free(param_1);
  return;
}



/* 4094aeb0 FUN_4094aeb0 */

/* Boundary evidence: original MIPS .pdata 4094aeb0..4094af2b. Semantic name remains unreviewed. */

void FUN_4094aeb0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = true;
  uVar3 = 0x10;
  do {
    iVar4 = 0xc;
    do {
      piVar2 = (int *)(*(int *)(param_1 + 0x20) + uVar3);
      if (param_2 == *piVar2) {
        *piVar2 = 0;
      }
      if (*(int *)(*(int *)(param_1 + 0x20) + uVar3) != 0) {
        bVar1 = false;
      }
      iVar4 = iVar4 + -1;
      uVar3 = uVar3 + 4;
    } while (iVar4 != 0);
  } while (uVar3 < 0x100);
  if (bVar1) {
    FUN_4094ae44(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 4094af2c FUN_4094af2c */

/* Boundary evidence: original MIPS .pdata 4094af2c..4094afc7. Semantic name remains unreviewed. */

void FUN_4094af2c(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  FUN_40955a14();
  iVar4 = *(int *)(param_1 + 0x20);
  uVar3 = 0;
  piVar1 = (int *)(iVar4 + 0x10);
  do {
    uVar2 = 0;
    do {
      if (*piVar1 != 0) {
        if (param_2 == 1) {
          mali_image_set_destroy_callback(iVar4,uVar3,uVar2,0);
        }
        else {
          mali_image_set_destroy_callback(iVar4,uVar3,uVar2,FUN_4094aeb0);
        }
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (uVar2 < 0xc);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 5);
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x18);
}



/* 4094afc8 FUN_4094afc8 */

/* Boundary evidence: original MIPS .pdata 4094afc8..4094b0c7. Semantic name remains unreviewed. */

void FUN_4094afc8(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_40955b34();
  mali_image_unlock_all_sessions(*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  if (param_2 == 1) {
    FUN_4094acf4(param_1);
  }
  iVar1 = mali_sys_lock_try_lock(*(undefined4 *)(param_1 + 0x1c));
  if (iVar1 == 0) {
    FUN_4094acf4(param_1);
    if (*(int *)(param_1 + 0x20) == 0) {
      FUN_4094bd58(param_1,0,5,param_4,param_5,param_6);
      if (*(int *)(param_1 + 0x18) != 0) {
        mali_sys_free();
      }
      mali_sys_lock_destroy(*(undefined4 *)(param_1 + 0x1c));
      mali_sys_free(param_1);
    }
    else {
      iVar1 = mali_image_deref();
      if (param_2 == 1) {
        while (iVar1 == 0) {
          iVar1 = mali_image_deref(*(undefined4 *)(param_1 + 0x20));
        }
      }
      if ((iVar1 != 1) && (*(int *)(*(int *)(param_1 + 0x20) + 0x10c) != 0)) {
        uVar2 = 1;
        FUN_4094af2c(param_1,1);
        FUN_4094ae44(param_1,uVar2,param_3,param_4);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094b0c8 FUN_4094b0c8 */

/* Boundary evidence: original MIPS .pdata 4094b0c8..4094b17b. Semantic name remains unreviewed. */

void FUN_4094b0c8(uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  FUN_40955b34();
  iVar2 = param_3;
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3008;
    }
  }
  else {
    iVar1 = FUN_4094b90c(param_2);
    if (iVar1 == 0) {
      if (param_3 != 0) {
        *(undefined4 *)(param_3 + 0x10) = 0x300c;
      }
    }
    else if (*(uint *)(iVar1 + 8) == param_1) {
      *(undefined4 *)(iVar1 + 0x14) = 0;
      FUN_4094afc8(iVar1,0,iVar2,param_4,param_5,param_6);
    }
    else if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3009;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094b17c FUN_4094b17c */

/* Boundary evidence: original MIPS .pdata 4094b17c..4094b3cf. Semantic name remains unreviewed. */

void FUN_4094b17c(uint param_1,uint param_2,uint param_3,int *param_4,int *param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  uint *puVar6;
  int *in_stack_00000048;
  int *in_stack_0000004c;
  
  FUN_40955a14();
  puVar6 = (uint *)0x0;
  piVar5 = param_4;
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (in_stack_0000004c != (int *)0x0) {
      in_stack_0000004c[4] = 0x3008;
    }
    goto LAB_4094b3c8;
  }
  iVar2 = FUN_4094bc38(param_2,param_1,(int)in_stack_0000004c);
  if (iVar2 == 0) goto LAB_4094b3c8;
  if (param_3 == 0x30b0) {
    param_5 = in_stack_0000004c;
    puVar6 = (uint *)FUN_40954938(iVar1,iVar2,param_4,in_stack_00000048,(int)in_stack_0000004c);
  }
  else if (param_3 == 0x30b1) {
    if ((*(uint *)(iVar2 + 0x28) & 2) == 0) goto LAB_4094b314;
    param_6 = in_stack_0000004c;
    param_5 = in_stack_00000048;
    piVar5 = param_4;
    puVar6 = (uint *)FUN_40954810(iVar1,iVar2,0x30b1,param_4,in_stack_00000048,in_stack_0000004c);
    in_stack_00000048 = piVar5;
  }
  else if (param_3 < 0x30b3) {
LAB_4094b32c:
    iVar1 = 0x300c;
LAB_4094b330:
    if (in_stack_0000004c == (int *)0x0) goto LAB_4094b3c8;
    in_stack_0000004c[4] = iVar1;
    in_stack_00000048 = piVar5;
  }
  else if (param_3 < 0x30b9) {
    if ((*(uint *)(iVar2 + 0x28) & 4) == 0) {
LAB_4094b314:
      iVar1 = 0x30a1;
LAB_4094b318:
      if (*(int *)(iVar2 + 8) != iVar1) goto LAB_4094b32c;
      iVar1 = 0x3009;
      goto LAB_4094b330;
    }
    param_6 = in_stack_0000004c;
    param_5 = in_stack_00000048;
    piVar5 = param_4;
    puVar6 = (uint *)FUN_40954810(iVar1,iVar2,param_3,param_4,in_stack_00000048,in_stack_0000004c);
    in_stack_00000048 = piVar5;
  }
  else {
    if (param_3 != 0x30b9) {
      if (param_3 == 0x30ba) {
        if ((*(uint *)(iVar2 + 0x28) & 1) != 0) {
          param_6 = in_stack_0000004c;
          param_5 = in_stack_00000048;
          piVar5 = param_4;
          puVar6 = (uint *)FUN_409546c8(iVar1,iVar2,0x30ba,(int)param_4,in_stack_00000048,
                                        in_stack_0000004c);
          in_stack_00000048 = piVar5;
          goto LAB_4094b35c;
        }
        iVar1 = 0x30a0;
        goto LAB_4094b318;
      }
      goto LAB_4094b32c;
    }
    if ((*(uint *)(iVar2 + 0x28) & 0x10) == 0) goto LAB_4094b314;
    param_6 = in_stack_0000004c;
    param_5 = in_stack_00000048;
    piVar5 = param_4;
    puVar6 = (uint *)FUN_40954810(iVar1,iVar2,0x30b9,param_4,in_stack_00000048,in_stack_0000004c);
    in_stack_00000048 = piVar5;
  }
LAB_4094b35c:
  if (puVar6 != (uint *)0x0) {
    puVar6[2] = param_1;
    puVar6[3] = param_2;
    *puVar6 = param_3;
    puVar6[1] = (uint)param_4;
    FUN_4094af2c((int)puVar6,0);
    uVar4 = 5;
    uVar3 = FUN_4094c4ec((int)puVar6,0,5);
    if (((uVar3 == 0) || ((uVar3 | 0x10000000) == 0)) &&
       (FUN_4094afc8((int)puVar6,0,uVar4,in_stack_00000048,param_5,param_6),
       in_stack_0000004c != (int *)0x0)) {
      in_stack_0000004c[4] = 0x3003;
    }
  }
LAB_4094b3c8:
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x18);
}



/* 4094b3d0 FUN_4094b3d0 */

/* Boundary evidence: original MIPS .pdata 4094b3d0..4094b473. Semantic name remains unreviewed. */

undefined4 FUN_4094b3d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = __mali_named_list_allocate();
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = __mali_named_list_allocate();
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  iVar2 = __mali_named_list_allocate();
  iVar3 = *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x2c) = iVar2;
  if (iVar3 != 0) {
    if ((*(int *)(param_1 + 0x28) != 0) && (iVar2 != 0)) {
      return 1;
    }
    if (iVar3 != 0) {
      __mali_named_list_free(iVar3,0);
    }
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 0x28),0);
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 0x2c),0);
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return 0;
}



/* 4094b474 FUN_4094b474 */

/* Boundary evidence: original MIPS .pdata 4094b474..4094b4af. Semantic name remains unreviewed. */

undefined4 FUN_4094b474(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = *(undefined4 *)((param_2 + 7) * 4 + param_1);
  }
  else {
    uVar1 = __mali_named_list_get_non_flat();
  }
  return uVar1;
}



/* 4094b544 FUN_4094b544 */

/* Boundary evidence: original MIPS .pdata 4094b544..4094b5ff. Semantic name remains unreviewed. */

undefined4 FUN_4094b544(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  
  piVar1 = FUN_409519bc();
  iVar2 = __mali_named_list_iterate_begin(*piVar1,auStack_1c);
  do {
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar2 + 0x2c),auStack_20);
    while (iVar3 != 0) {
      if ((*(int *)(iVar3 + 0xc) == 1) && (param_1 == *(int *)(iVar3 + 200))) {
        return 1;
      }
      iVar3 = __mali_named_list_iterate_next(*(undefined4 *)(iVar2 + 0x2c),auStack_20);
    }
    iVar2 = __mali_named_list_iterate_next(*piVar1,auStack_1c);
  } while( true );
}



/* 4094b600 FUN_4094b600 */

/* Boundary evidence: original MIPS .pdata 4094b600..4094b69b. Semantic name remains unreviewed. */

void FUN_4094b600(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  iVar2 = __mali_named_list_iterate_begin(*piVar1,&stack0x00000014);
  while (iVar2 != 0) {
    iVar3 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar2 + 0x2c),&stack0x00000010);
    while (iVar3 != 0) {
      if ((*(int *)(iVar3 + 0xc) == 2) && (param_1 == *(int *)(iVar3 + 4))) goto LAB_4094b68c;
      iVar3 = __mali_named_list_iterate_next(*(undefined4 *)(iVar2 + 0x2c),&stack0x00000010);
    }
    iVar2 = __mali_named_list_iterate_next(*piVar1,&stack0x00000014);
  }
LAB_4094b68c:
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x18);
}



/* 4094b69c FUN_4094b69c */

/* Boundary evidence: original MIPS .pdata 4094b69c..4094b737. Semantic name remains unreviewed. */

void FUN_4094b69c(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  if (param_1 != 0) {
    iVar2 = __mali_named_list_iterate_begin(*piVar1,&stack0x00000014);
    while (iVar2 != 0) {
      piVar3 = (int *)__mali_named_list_iterate_begin
                                (*(undefined4 *)(iVar2 + 0x2c),&stack0x00000010);
      while (piVar3 != (int *)0x0) {
        if ((piVar3[3] == 0) && (param_1 == *piVar3)) goto LAB_4094b728;
        piVar3 = (int *)__mali_named_list_iterate_next
                                  (*(undefined4 *)(iVar2 + 0x2c),&stack0x00000010);
      }
      iVar2 = __mali_named_list_iterate_next(*piVar1,&stack0x00000014);
    }
  }
LAB_4094b728:
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x18);
}



/* 4094b738 FUN_4094b738 */

/* Boundary evidence: original MIPS .pdata 4094b738..4094b75f. Semantic name remains unreviewed. */

void FUN_4094b738(void)

{
  int *piVar1;
  undefined1 auStack_10 [8];
  
  piVar1 = FUN_409519bc();
  __mali_named_list_iterate_begin(*piVar1,auStack_10);
  return;
}



/* 4094b760 FUN_4094b760 */

/* Boundary evidence: original MIPS .pdata 4094b760..4094b7cf. Semantic name remains unreviewed. */

undefined4 FUN_4094b760(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_18 [2];
  
  piVar1 = FUN_409519bc();
  piVar2 = (int *)__mali_named_list_iterate_begin(*piVar1,local_18);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if (param_1 == *piVar2) break;
    piVar2 = (int *)__mali_named_list_iterate_next(*piVar1,local_18);
  }
  return local_18[0];
}



/* 4094b7d0 FUN_4094b7d0 */

/* Boundary evidence: original MIPS .pdata 4094b7d0..4094b90b. Semantic name remains unreviewed. */

void FUN_4094b7d0(uint param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40955ae4();
  piVar1 = FUN_409519bc();
  if (param_3 == 1) {
    if ((param_1 & 0x70000000) != 0) goto LAB_4094b904;
  }
  else {
    if ((param_2 & 0x70000000) != 0) goto LAB_4094b904;
    uVar3 = (param_2 ^ 0x70000000) & param_2;
    if (uVar3 < 0x100) {
      iVar2 = *(int *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if (param_3 == 2) {
      if (iVar2 == 0) goto LAB_4094b904;
      uVar3 = 0x20000000;
    }
    else if (param_3 == 3) {
      if (iVar2 == 0) goto LAB_4094b904;
      uVar3 = 0x40000000;
    }
    else if (param_3 == 4) {
      if (iVar2 == 0) goto LAB_4094b904;
      uVar3 = 0x60000000;
    }
    else {
      if (param_3 != 5) goto LAB_4094b904;
      uVar3 = 0x10000000;
    }
    if ((param_1 & 0x70000000) != uVar3) goto LAB_4094b904;
  }
  if (0xff < ((param_1 ^ 0x70000000) & param_1)) {
    __mali_named_list_get_non_flat();
  }
LAB_4094b904:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x10);
}



/* 4094b90c FUN_4094b90c */

/* Boundary evidence: original MIPS .pdata 4094b90c..4094b97b. Semantic name remains unreviewed. */

undefined4 FUN_4094b90c(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  piVar1 = FUN_409519bc();
  if ((param_1 & 0x70000000) == 0x10000000) {
    uVar3 = (param_1 ^ 0x70000000) & param_1;
    if (uVar3 < 0x100) {
      uVar2 = *(undefined4 *)((uVar3 + 7) * 4 + piVar1[0x12]);
    }
    else {
      uVar2 = __mali_named_list_get_non_flat();
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4094b97c FUN_4094b97c */

/* Boundary evidence: original MIPS .pdata 4094b97c..4094ba2b. Semantic name remains unreviewed. */

void FUN_4094b97c(uint param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  if ((param_2 & 0x70000000) == 0) {
    uVar3 = (param_2 ^ 0x70000000) & param_2;
    if (uVar3 < 0x100) {
      iVar2 = *(int *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if (((iVar2 != 0) && ((param_1 & 0x70000000) == 0x40000000)) &&
       (0xff < ((param_1 ^ 0x70000000) & param_1))) {
      __mali_named_list_get_non_flat();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094ba2c FUN_4094ba2c */

/* Boundary evidence: original MIPS .pdata 4094ba2c..4094badb. Semantic name remains unreviewed. */

void FUN_4094ba2c(uint param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  if ((param_2 & 0x70000000) == 0) {
    uVar3 = (param_2 ^ 0x70000000) & param_2;
    if (uVar3 < 0x100) {
      iVar2 = *(int *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if (((iVar2 != 0) && ((param_1 & 0x70000000) == 0x20000000)) &&
       (0xff < ((param_1 ^ 0x70000000) & param_1))) {
      __mali_named_list_get_non_flat();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094badc FUN_4094badc */

/* Boundary evidence: original MIPS .pdata 4094badc..4094bb8b. Semantic name remains unreviewed. */

void FUN_4094badc(uint param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40955b34();
  piVar1 = FUN_409519bc();
  if ((param_2 & 0x70000000) == 0) {
    uVar3 = (param_2 ^ 0x70000000) & param_2;
    if (uVar3 < 0x100) {
      iVar2 = *(int *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if (((iVar2 != 0) && ((param_1 & 0x70000000) == 0x60000000)) &&
       (0xff < ((param_1 ^ 0x70000000) & param_1))) {
      __mali_named_list_get_non_flat();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094bb8c FUN_4094bb8c */

/* Boundary evidence: original MIPS .pdata 4094bb8c..4094bbf7. Semantic name remains unreviewed. */

undefined4 FUN_4094bb8c(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  piVar1 = FUN_409519bc();
  if ((param_1 & 0x70000000) == 0) {
    uVar3 = (param_1 ^ 0x70000000) & param_1;
    if (uVar3 < 0x100) {
      uVar2 = *(undefined4 *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      uVar2 = __mali_named_list_get_non_flat();
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4094bbf8 FUN_4094bbf8 */

/* Boundary evidence: original MIPS .pdata 4094bbf8..4094bc37. Semantic name remains unreviewed. */

int FUN_4094bbf8(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_4094b90c(param_1);
  if (iVar1 == 0) {
    if (param_2 != 0) {
      *(undefined4 *)(param_2 + 0x10) = 0x300c;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4094bc38 FUN_4094bc38 */

/* Boundary evidence: original MIPS .pdata 4094bc38..4094bc87. Semantic name remains unreviewed. */

int FUN_4094bc38(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_4094b97c(param_1,param_2);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x24) != 1)) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3006;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4094bc88 FUN_4094bc88 */

/* Boundary evidence: original MIPS .pdata 4094bc88..4094bcd7. Semantic name remains unreviewed. */

int FUN_4094bc88(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_4094ba2c(param_1,param_2);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0xa8) != 1)) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x300d;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4094bcd8 FUN_4094bcd8 */

/* Boundary evidence: original MIPS .pdata 4094bcd8..4094bd17. Semantic name remains unreviewed. */

int FUN_4094bcd8(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_4094badc(param_1,param_2);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3005;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4094bd18 FUN_4094bd18 */

/* Boundary evidence: original MIPS .pdata 4094bd18..4094bd57. Semantic name remains unreviewed. */

int FUN_4094bd18(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_2 != 0) {
      *(undefined4 *)(param_2 + 0x10) = 0x3008;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4094bd58 FUN_4094bd58 */

/* Boundary evidence: original MIPS .pdata 4094bd58..4094be97. Semantic name remains unreviewed. */

void FUN_4094bd58(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_40955ae4();
  piVar1 = FUN_409519bc();
  if (param_3 == 1) {
    iVar3 = *piVar1;
  }
  else if (param_3 == 2) {
    iVar3 = FUN_4094bb8c(param_2);
    iVar3 = *(int *)(iVar3 + 0x2c);
  }
  else if (param_3 == 3) {
    iVar3 = FUN_4094bb8c(param_2);
    iVar3 = *(int *)(iVar3 + 0x28);
  }
  else {
    if (param_3 != 5) goto LAB_4094be08;
    iVar3 = piVar1[0x12];
  }
  iVar2 = __mali_named_list_iterate_begin(iVar3,&param_6);
  while (iVar2 != 0) {
    if (param_1 == iVar2) {
      if (param_3 == 1) {
        iVar3 = *(int *)(iVar2 + 0x24);
        if (iVar3 != 0) {
          while( true ) {
            iVar3 = __mali_named_list_iterate_begin(iVar3,&param_5);
            if (iVar3 == 0) break;
            __mali_named_list_remove(*(undefined4 *)(iVar2 + 0x24),param_5);
            iVar3 = *(int *)(iVar2 + 0x24);
          }
          __mali_named_list_free(*(undefined4 *)(iVar2 + 0x24),0);
        }
        if (*(int *)(iVar2 + 0x28) != 0) {
          __mali_named_list_free(*(int *)(iVar2 + 0x28),0);
        }
        if (*(int *)(iVar2 + 0x2c) != 0) {
          __mali_named_list_free(*(int *)(iVar2 + 0x2c),0);
        }
      }
      else {
        __mali_named_list_remove(iVar3,param_6);
      }
      break;
    }
    iVar2 = __mali_named_list_iterate_next(iVar3,&param_6);
  }
LAB_4094be08:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 4094be98 FUN_4094be98 */

/* Boundary evidence: original MIPS .pdata 4094be98..4094bf1b. Semantic name remains unreviewed. */

uint FUN_4094be98(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint local_18 [2];
  
  iVar1 = FUN_4094bb8c(param_2);
  if (iVar1 != 0) {
    iVar2 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x24),local_18);
    while (iVar2 != 0) {
      if (param_1 == *(int *)(iVar2 + 0x2c)) {
        return local_18[0] | 0x60000000;
      }
      iVar2 = __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x24),local_18);
    }
  }
  return 0;
}



/* 4094bf1c FUN_4094bf1c */

/* Boundary evidence: original MIPS .pdata 4094bf1c..4094bfcb. Semantic name remains unreviewed. */

int FUN_4094bf1c(uint *param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_20 [2];
  
  iVar3 = 0;
  iVar1 = FUN_4094bb8c(param_2);
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar2 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x24),local_20);
    if (0 < param_3) {
      do {
        if (iVar2 == 0) {
          return iVar3;
        }
        *param_1 = local_20[0] | 0x60000000;
        iVar3 = iVar3 + 1;
        iVar2 = __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x24),local_20);
        param_1 = param_1 + 1;
      } while (iVar3 < param_3);
    }
  }
  return iVar3;
}



/* 4094bfcc FUN_4094bfcc */

/* Boundary evidence: original MIPS .pdata 4094bfcc..4094c0d3. Semantic name remains unreviewed. */

undefined4 FUN_4094bfcc(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20 [2];
  
  piVar1 = FUN_409519bc();
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = FUN_4094bb8c(param_2);
  if (param_3 == 1) {
    iVar2 = *piVar1;
  }
  else if (param_3 == 2) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x2c);
  }
  else if (param_3 == 3) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x28);
  }
  else if (param_3 == 4) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x24);
  }
  else {
    if (param_3 != 5) {
      return 0;
    }
    iVar2 = piVar1[0x12];
  }
  iVar3 = __mali_named_list_iterate_begin(iVar2,local_20);
  while( true ) {
    if (iVar3 == 0) {
      return 0;
    }
    if (param_1 == iVar3) break;
    iVar3 = __mali_named_list_iterate_next(iVar2,local_20);
  }
  return local_20[0];
}



/* 4094c0d4 FUN_4094c0d4 */

/* Boundary evidence: original MIPS .pdata 4094c0d4..4094c0f3. Semantic name remains unreviewed. */

void FUN_4094c0d4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  FUN_4094bd58(param_1,0,5,param_4,unaff_retaddr,in_stack_fffffffc);
  return;
}



/* 4094c0f4 FUN_4094c0f4 */

/* Boundary evidence: original MIPS .pdata 4094c0f4..4094c10f. Semantic name remains unreviewed. */

void FUN_4094c0f4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  FUN_4094bd58(param_1,param_2,3,param_4,unaff_retaddr,in_stack_fffffffc);
  return;
}



/* 4094c110 FUN_4094c110 */

/* Boundary evidence: original MIPS .pdata 4094c110..4094c12b. Semantic name remains unreviewed. */

void FUN_4094c110(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  FUN_4094bd58(param_1,param_2,2,param_4,unaff_retaddr,in_stack_fffffffc);
  return;
}



/* 4094c12c FUN_4094c12c */

/* Boundary evidence: original MIPS .pdata 4094c12c..4094c1d7. Semantic name remains unreviewed. */

undefined4 FUN_4094c12c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  piVar1 = FUN_409519bc();
  iVar2 = FUN_4094bd58(param_1,0,1,param_4,in_stack_ffffffe0,in_stack_ffffffe4);
  if ((iVar2 == 1) && (param_2 == 1)) {
    iVar2 = __mali_named_list_iterate_begin(*piVar1,&stack0xffffffe0);
    while (iVar2 != 0) {
      if (param_1 == iVar2) {
        __mali_named_list_remove(*piVar1,in_stack_ffffffe0);
        return 1;
      }
      iVar2 = __mali_named_list_iterate_next(*piVar1,&stack0xffffffe0);
    }
  }
  return 0;
}



/* 4094c1d8 FUN_4094c1d8 */

/* Boundary evidence: original MIPS .pdata 4094c1d8..4094c20f. Semantic name remains unreviewed. */

uint FUN_4094c1d8(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_4094bfcc(param_1,0,5);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x10000000;
  }
  return uVar1;
}



/* 4094c210 FUN_4094c210 */

/* Boundary evidence: original MIPS .pdata 4094c210..4094c243. Semantic name remains unreviewed. */

uint FUN_4094c210(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4094bfcc(param_1,param_2,3);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x40000000;
  }
  return uVar1;
}



/* 4094c244 FUN_4094c244 */

/* Boundary evidence: original MIPS .pdata 4094c244..4094c277. Semantic name remains unreviewed. */

uint FUN_4094c244(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4094bfcc(param_1,param_2,2);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x20000000;
  }
  return uVar1;
}



/* 4094c278 FUN_4094c278 */

/* Boundary evidence: original MIPS .pdata 4094c278..4094c2ab. Semantic name remains unreviewed. */

uint FUN_4094c278(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4094bfcc(param_1,param_2,4);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x60000000;
  }
  return uVar1;
}



/* 4094c2ac FUN_4094c2ac */

/* Boundary evidence: original MIPS .pdata 4094c2ac..4094c2cb. Semantic name remains unreviewed. */

void FUN_4094c2ac(int param_1)

{
  FUN_4094bfcc(param_1,0,1);
  return;
}



/* 4094c2cc FUN_4094c2cc */

/* Boundary evidence: original MIPS .pdata 4094c2cc..4094c3c7. Semantic name remains unreviewed. */

void FUN_4094c2cc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5
                 ,uint param_6)

{
  int iVar1;
  int iVar2;
  
  FUN_40955b34();
  param_5 = 0;
  param_6 = 0;
  iVar1 = FUN_4094bb8c(param_1);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x28) != 0)) &&
     (iVar2 = __mali_named_list_size(), iVar2 != 0)) {
    iVar2 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x28),&param_5);
    while (iVar2 != 0) {
      FUN_409525cc(param_1,iVar2,1,param_4);
      if (param_5 < 0x100) {
        iVar2 = *(int *)((param_5 + 7) * 4 + *(int *)(iVar1 + 0x28));
      }
      else {
        iVar2 = __mali_named_list_get_non_flat(*(int *)(iVar1 + 0x28),param_5);
      }
      if (iVar2 == 0) {
        if (param_6 == 0) {
          iVar2 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x28),&param_5);
        }
        else {
          iVar2 = __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x28),&param_6);
        }
      }
      else {
        param_6 = param_5;
        iVar2 = __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x28),&param_5);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x18);
}



/* 4094c3c8 FUN_4094c3c8 */

/* Boundary evidence: original MIPS .pdata 4094c3c8..4094c4eb. Semantic name remains unreviewed. */

undefined4 FUN_4094c3c8(uint param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint local_20;
  uint local_1c;
  
  local_20 = 0;
  local_1c = 0;
  uVar4 = 1;
  iVar1 = FUN_4094bb8c(param_1);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x2c) != 0)) &&
     (iVar2 = __mali_named_list_size(), iVar2 != 0)) {
    puVar3 = (undefined4 *)__mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x2c),&local_20);
    while (puVar3 != (undefined4 *)0x0) {
      FUN_4094d90c(param_1,puVar3,1,param_2);
      if (local_20 < 0x100) {
        iVar2 = *(int *)((local_20 + 7) * 4 + *(int *)(iVar1 + 0x2c));
      }
      else {
        iVar2 = __mali_named_list_get_non_flat(*(int *)(iVar1 + 0x2c),local_20);
      }
      if (iVar2 == 0) {
        if (local_1c == 0) {
          puVar3 = (undefined4 *)
                   __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x2c),&local_20);
        }
        else {
          puVar3 = (undefined4 *)
                   __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x2c),&local_1c);
        }
      }
      else {
        local_1c = local_20;
        puVar3 = (undefined4 *)
                 __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x2c),&local_20);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



/* 4094c4ec FUN_4094c4ec */

/* Boundary evidence: original MIPS .pdata 4094c4ec..4094c663. Semantic name remains unreviewed. */

void FUN_4094c4ec(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  FUN_40955ae4();
  piVar1 = FUN_409519bc();
  iVar2 = FUN_4094bb8c(param_2);
  if (param_3 == 1) {
    iVar2 = FUN_4094bfcc(param_1,0,1);
    if (iVar2 != 0) goto LAB_4094c658;
    iVar2 = *piVar1;
  }
  else if (param_3 == 2) {
    uVar3 = FUN_4094bfcc(param_1,param_2,2);
    if ((uVar3 != 0) && ((uVar3 | 0x20000000) != 0)) goto LAB_4094c658;
    iVar2 = *(int *)(iVar2 + 0x2c);
  }
  else if (param_3 == 3) {
    uVar3 = FUN_4094bfcc(param_1,param_2,3);
    if ((uVar3 != 0) && ((uVar3 | 0x40000000) != 0)) goto LAB_4094c658;
    iVar2 = *(int *)(iVar2 + 0x28);
  }
  else if (param_3 == 4) {
    uVar3 = FUN_4094bfcc(param_1,param_2,4);
    if ((uVar3 != 0) && ((uVar3 | 0x60000000) != 0)) goto LAB_4094c658;
    iVar2 = *(int *)(iVar2 + 0x24);
  }
  else {
    if ((param_3 != 5) ||
       ((uVar3 = FUN_4094bfcc(param_1,0,5), uVar3 != 0 && ((uVar3 | 0x10000000) != 0))))
    goto LAB_4094c658;
    iVar2 = piVar1[0x12];
  }
  uVar4 = __mali_named_list_get_unused_name(iVar2);
  __mali_named_list_insert(iVar2,uVar4,param_1);
LAB_4094c658:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x10);
}



/* 4094c664 FUN_4094c664 */

/* Boundary evidence: original MIPS .pdata 4094c664..4094c69b. Semantic name remains unreviewed. */

uint FUN_4094c664(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_4094c4ec(param_1,0,5);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x10000000;
  }
  return uVar1;
}



/* 4094c69c FUN_4094c69c */

/* Boundary evidence: original MIPS .pdata 4094c69c..4094c6cf. Semantic name remains unreviewed. */

uint FUN_4094c69c(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4094c4ec(param_1,param_2,3);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x40000000;
  }
  return uVar1;
}



/* 4094c6d0 FUN_4094c6d0 */

/* Boundary evidence: original MIPS .pdata 4094c6d0..4094c703. Semantic name remains unreviewed. */

uint FUN_4094c6d0(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4094c4ec(param_1,param_2,2);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x20000000;
  }
  return uVar1;
}



/* 4094c704 FUN_4094c704 */

/* Boundary evidence: original MIPS .pdata 4094c704..4094c737. Semantic name remains unreviewed. */

uint FUN_4094c704(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4094c4ec(param_1,param_2,4);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x60000000;
  }
  return uVar1;
}



/* 4094c738 FUN_4094c738 */

/* Boundary evidence: original MIPS .pdata 4094c738..4094c757. Semantic name remains unreviewed. */

void FUN_4094c738(int param_1)

{
  FUN_4094c4ec(param_1,0,1);
  return;
}



/* 4094c758 FUN_4094c758 */

/* Boundary evidence: original MIPS .pdata 4094c758..4094c80b. Semantic name remains unreviewed. */

void FUN_4094c758(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  iVar3 = param_3;
  if (param_1 == 0) {
    return;
  }
  do {
    iVar1 = __mali_named_list_iterate_begin(param_1,&stack0xffffffe0);
    while( true ) {
      if (iVar1 == 0) {
        return;
      }
      if (((param_2 == *(int *)(iVar1 + 8)) || (param_2 == 0)) &&
         (iVar2 = FUN_4094afc8(iVar1,param_3,iVar3,param_4,in_stack_ffffffe0,in_stack_ffffffe4),
         iVar2 == 1)) break;
      iVar1 = __mali_named_list_iterate_next(param_1,&stack0xffffffe0);
    }
    iVar3 = 5;
    FUN_4094bd58(iVar1,0,5,param_4,in_stack_ffffffe0,in_stack_ffffffe4);
  } while( true );
}



/* 4094c80c FUN_4094c80c */

undefined4 FUN_4094c80c(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x30a0;
  if (param_1[3] == 0x30a0) {
    uVar1 = param_1[1];
  }
  else {
    uVar2 = 0x30a1;
    if (param_1[3] != 0x30a1) {
      uVar1 = 0;
      if (param_2 == (undefined4 *)0x0) {
        return 0;
      }
      uVar2 = 0x3038;
      goto LAB_4094c84c;
    }
    uVar1 = *param_1;
  }
  if (param_2 == (undefined4 *)0x0) {
    return uVar1;
  }
LAB_4094c84c:
  *param_2 = uVar2;
  return uVar1;
}



/* 4094c858 FUN_4094c858 */

/* Boundary evidence: original MIPS .pdata 4094c858..4094c893. Semantic name remains unreviewed. */

undefined4 FUN_4094c858(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = *(undefined4 *)((param_2 + 7) * 4 + param_1);
  }
  else {
    uVar1 = __mali_named_list_get_non_flat();
  }
  return uVar1;
}



/* 4094c894 FUN_4094c894 */

/* Boundary evidence: original MIPS .pdata 4094c894..4094c8af. Semantic name remains unreviewed. */

void FUN_4094c894(void)

{
  FUN_40951c14(1);
  return;
}



/* 4094c8b0 FUN_4094c8b0 */

/* Boundary evidence: original MIPS .pdata 4094c8b0..4094c9b3. Semantic name remains unreviewed. */

undefined4 FUN_4094c8b0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int in_stack_ffffffec;
  
  puVar1 = (undefined4 *)mali_sys_thread_key_get_data(0);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = puVar1[2];
    if ((int *)puVar1[1] != (int *)0x0) {
      uVar2 = FUN_4094bfcc(*(int *)puVar1[1],0,1);
      puVar1[3] = 0x30a0;
      FUN_409529a8(uVar2,0,(int *)0x0,0,puVar1,in_stack_ffffffec);
      mali_sys_free(puVar1[1]);
      puVar1[1] = 0;
      puVar1[7] = 0;
    }
    if ((int *)*puVar1 != (int *)0x0) {
      uVar2 = FUN_4094bfcc(*(int *)*puVar1,0,1);
      puVar1[3] = 0x30a1;
      FUN_409529a8(uVar2,0,(int *)0x0,0,puVar1,in_stack_ffffffec);
      mali_sys_free(*puVar1);
      *puVar1 = 0;
      puVar1[6] = 0;
    }
    __mali_named_list_lock(*(undefined4 *)(iVar3 + 8));
    mali_sys_thread_key_set_data(0,0);
    __mali_named_list_remove(*(undefined4 *)(iVar3 + 8),puVar1[5]);
    mali_sys_free(puVar1);
    __mali_named_list_unlock(*(undefined4 *)(iVar3 + 8));
  }
  return 1;
}



/* 4094c9b4 FUN_4094c9b4 */

/* Boundary evidence: original MIPS .pdata 4094c9b4..4094cbfb. Semantic name remains unreviewed. */

void FUN_4094c9b4(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int in_stack_00000014;
  
  FUN_40955ae4();
  iVar1 = mali_sys_thread_key_get_data(0);
  if (iVar1 == 0) {
    piVar2 = FUN_409519bc();
    if ((piVar2 == (int *)0x0) ||
       (puVar3 = (undefined4 *)mali_sys_calloc(1,0x20), puVar3 == (undefined4 *)0x0))
    goto LAB_4094cbf0;
    puVar3[3] = 0x30a0;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[4] = 0x3000;
    puVar3[2] = piVar2;
    uVar4 = mali_sys_thread_get_current();
    puVar3[5] = uVar4;
    puVar3[6] = 0;
    puVar3[7] = 0;
    __mali_named_list_lock(piVar2[2]);
    iVar1 = __mali_named_list_insert(piVar2[2],puVar3[5],puVar3);
    if (iVar1 == -2) {
      if ((uint)puVar3[5] < 0x100) {
        piVar7 = *(int **)((puVar3[5] + 7) * 4 + piVar2[2]);
      }
      else {
        piVar7 = (int *)__mali_named_list_get_non_flat();
      }
      if (piVar7 != (int *)0x0) {
        if ((int *)piVar7[1] != (int *)0x0) {
          uVar5 = FUN_4094bfcc(*(int *)piVar7[1],0,1);
          iVar1 = FUN_40952154(0x30a0,piVar7);
          iVar6 = piVar7[1];
          if ((((*(int *)(iVar6 + 0xc) != 0) || (*(int *)(iVar6 + 4) != 0)) ||
              (*(int *)(iVar6 + 8) != 0)) && (iVar1 == 1)) {
            FUN_409529a8(uVar5,0,(int *)0x0,0,piVar7,in_stack_00000014);
          }
          mali_sys_free(piVar7[1]);
          piVar7[1] = 0;
        }
        if ((int *)*piVar7 != (int *)0x0) {
          uVar5 = FUN_4094bfcc(*(int *)*piVar7,0,1);
          iVar1 = FUN_40952154(0x30a1,piVar7);
          iVar6 = *piVar7;
          if ((((*(int *)(iVar6 + 0xc) != 0) || (*(int *)(iVar6 + 4) != 0)) ||
              (*(int *)(iVar6 + 8) != 0)) && (iVar1 == 1)) {
            FUN_409529a8(uVar5,0,(int *)0x0,0,piVar7,in_stack_00000014);
          }
          mali_sys_free(*piVar7);
          *piVar7 = 0;
        }
        mali_sys_free(piVar7);
      }
      iVar1 = __mali_named_list_set(piVar2[2],puVar3[5],puVar3);
    }
    __mali_named_list_unlock(piVar2[2]);
    if ((iVar1 != 0) || (iVar1 = mali_sys_thread_key_set_data(0,puVar3), iVar1 != 0)) {
      mali_sys_free(puVar3);
      goto LAB_4094cbf0;
    }
  }
  FUN_40951c14(0);
LAB_4094cbf0:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 4094cbfc FUN_4094cbfc */

void FUN_4094cbfc(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0xcc) = 0x3089;
  *(undefined4 *)(param_1 + 0xc4) = 0x308b;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0xb8) = param_2;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (param_4 == 2) {
    *(undefined4 *)(param_1 + 0xe4) = 0x3085;
    *(undefined4 *)(param_1 + 4) = *param_3;
  }
  else {
    *(undefined4 *)(param_1 + 0xe4) = 0x3084;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0x305c;
  *(undefined4 *)(param_1 + 0xf4) = 0x305c;
  *(undefined4 *)(param_1 + 0xe8) = 0x3095;
  *(undefined4 *)(param_1 + 0xec) = 0x309a;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xf8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 1;
  *(undefined2 *)(param_1 + 0x70) = 0;
  *(undefined2 *)(param_1 + 0x72) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  return;
}



/* 4094ccac FUN_4094ccac */

/* Boundary evidence: original MIPS .pdata 4094ccac..4094cd1b. Semantic name remains unreviewed. */

int FUN_4094ccac(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 4094cd1c FUN_4094cd1c */

/* Boundary evidence: original MIPS .pdata 4094cd1c..4094d013. Semantic name remains unreviewed. */

void FUN_4094cd1c(int param_1,int *param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint *in_stack_00000020;
  uint *in_stack_00000024;
  int in_stack_00000028;
  
  FUN_40955b34();
  if (in_stack_00000028 == 1) {
    *in_stack_00000020 = 0;
    *in_stack_00000024 = 0;
  }
  if (param_2 == (int *)0x0) {
LAB_4094d00c:
                    /* WARNING: Subroutine does not return */
    FUN_40955b54(0);
  }
  bVar1 = false;
LAB_4094cd64:
  iVar4 = *param_2;
  if (iVar4 < 0x3082) {
    if (iVar4 == 0x3081) {
      if (param_2[1] != 0x305c) {
        if ((((*(uint *)(param_3 + 0x5c) & 1) == 0) && ((*(uint *)(param_3 + 0x5c) & 4) == 0)) ||
           (param_2[1] != 0x305f)) goto LAB_4094cff8;
        *(undefined4 *)(param_4 + 0xf4) = 0x305f;
      }
LAB_4094cfd4:
      prefetch(param_2 + 4,0);
      param_2 = param_2 + 2;
      if (bVar1) goto LAB_4094d00c;
      goto LAB_4094cd64;
    }
    if (iVar4 == 0x3038) {
      bVar1 = true;
      goto LAB_4094cfd4;
    }
    if (iVar4 == 0x3056) {
      if (in_stack_00000028 != 1) goto LAB_4094cff8;
      uVar5 = param_2[1];
      if ((-1 < (int)uVar5) && (uVar5 < 0x1001)) {
        *in_stack_00000024 = uVar5;
        *(uint *)(param_4 + 0xc0) = uVar5;
        goto LAB_4094cfd4;
      }
LAB_4094cfe8:
      if (param_1 == 0) goto LAB_4094d00c;
      uVar3 = 0x300c;
      goto LAB_4094d004;
    }
    if (iVar4 == 0x3057) {
      if (in_stack_00000028 == 1) {
        uVar5 = param_2[1];
        if (((int)uVar5 < 0) || (0x1000 < uVar5)) goto LAB_4094cfe8;
        *in_stack_00000020 = uVar5;
        *(uint *)(param_4 + 0xbc) = uVar5;
        goto LAB_4094cfd4;
      }
    }
    else if (iVar4 == 0x3058) {
      iVar4 = param_2[1];
      if ((iVar4 == 0) || (iVar4 == 1)) {
        *(int *)(param_4 + 0xd4) = iVar4;
        goto LAB_4094cfd4;
      }
    }
    else if (iVar4 == 0x3080) {
      iVar4 = param_2[1];
      if (iVar4 == 0x305c) goto LAB_4094cfd4;
      if (((*(uint *)(param_3 + 0x5c) & 1) != 0) || ((*(uint *)(param_3 + 0x5c) & 4) != 0)) {
        if (iVar4 == 0x305d) {
          iVar2 = *(int *)(param_3 + 0x1c);
        }
        else {
          if (iVar4 != 0x305e) goto LAB_4094cff8;
          iVar2 = *(int *)(param_3 + 0x20);
        }
        if (iVar2 == 0) goto LAB_4094ce08;
        *(int *)(param_4 + 0xf0) = iVar4;
        goto LAB_4094cfd4;
      }
    }
  }
  else if (iVar4 == 0x3082) {
    if ((((*(uint *)(param_3 + 0x5c) & 1) != 0) || ((*(uint *)(param_3 + 0x5c) & 4) != 0)) &&
       ((iVar4 = param_2[1], iVar4 == 0 || (iVar4 == 1)))) {
      *(int *)(param_4 + 0xd8) = iVar4;
      goto LAB_4094cfd4;
    }
  }
  else if (iVar4 == 0x3086) {
    if ((param_2[1] == 0x3084) || (param_2[1] == 0x3085)) {
      *(undefined4 *)(param_4 + 0xe4) = 0x3084;
      goto LAB_4094cfd4;
    }
  }
  else {
    if (iVar4 != 0x3087) {
      if ((iVar4 != 0x3088) || ((iVar4 = param_2[1], iVar4 != 0x308b && (iVar4 != 0x308c))))
      goto LAB_4094cff8;
      if ((iVar4 != 0x308c) || ((*(uint *)(param_3 + 0x6c) & 0x40) != 0)) {
        *(int *)(param_4 + 0xc4) = iVar4;
        goto LAB_4094cfd4;
      }
LAB_4094ce08:
      if (param_1 != 0) {
        uVar3 = 0x3009;
        goto LAB_4094d004;
      }
      goto LAB_4094d00c;
    }
    iVar4 = param_2[1];
    if ((iVar4 == 0x3089) || (iVar4 == 0x308a)) {
      if ((iVar4 == 0x308a) && ((*(uint *)(param_3 + 0x6c) & 0x20) == 0)) goto LAB_4094ce08;
      *(int *)(param_4 + 0xcc) = iVar4;
      goto LAB_4094cfd4;
    }
  }
LAB_4094cff8:
  if (param_1 == 0) goto LAB_4094d00c;
  uVar3 = 0x3004;
LAB_4094d004:
  *(undefined4 *)(param_1 + 0x10) = uVar3;
  goto LAB_4094d00c;
}



/* 4094d014 FUN_4094d014 */

/* Boundary evidence: original MIPS .pdata 4094d014..4094d09b. Semantic name remains unreviewed. */

void FUN_4094d014(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_40955b34();
  if ((param_1[4] & 2) != 0) {
    iVar1 = mali_render_attachment_get_target(param_1[0x1a],0,0);
    iVar2 = mali_render_attachment_get_target(param_1[0x1a],1,0);
    mali_render_attachment_free(param_1[0x1a]);
    if (iVar1 != 0) {
      FUN_4094ccac(iVar1);
    }
    if ((iVar2 != 0) && (iVar1 != iVar2)) {
      FUN_4094ccac(iVar2);
    }
  }
  FUN_40949568(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094d09c FUN_4094d09c */

/* Boundary evidence: original MIPS .pdata 4094d09c..4094d1c3. Semantic name remains unreviewed. */

void FUN_4094d09c(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  FUN_40955b34();
  if (param_1[0x27] == 0) {
    if ((param_2 != (int *)0x0) && (param_1[0x32] != 0)) {
      FUN_40947148((int)param_1,param_2);
    }
    while ((param_1[7] == 1 || (param_1[0xc] == 1))) {
      mali_sys_yield();
    }
    piVar2 = param_1 + 9;
    iVar3 = 4;
    do {
      if (*piVar2 != 0) {
        mali_ds_consumer_release_connections(*piVar2,0,0,0x7fffffff);
        *piVar2 = 0;
      }
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + 5;
    } while (iVar3 != 0);
    if (((param_1[4] & 2) != 0) && (param_1[0x1a] != 0)) {
      iVar3 = mali_render_attachment_get_target(param_1[0x1a],0,0);
      iVar1 = mali_render_attachment_get_target(param_1[0x1a],1,0);
      mali_render_attachment_free(param_1[0x1a]);
      if (iVar3 != 0) {
        FUN_4094ccac(iVar3);
      }
      if ((iVar1 != 0) && (iVar3 != iVar1)) {
        FUN_4094ccac(iVar1);
      }
    }
    FUN_40949568(param_1);
    mali_sys_free(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094d1c4 FUN_4094d1c4 */

/* Boundary evidence: original MIPS .pdata 4094d1c4..4094d1e3. Semantic name remains unreviewed. */

void FUN_4094d1c4(undefined4 param_1,undefined4 *param_2)

{
  FUN_4094f994(param_2,0);
  return;
}



/* 4094d1e4 FUN_4094d1e4 */

/* Boundary evidence: original MIPS .pdata 4094d1e4..4094d3df. Semantic name remains unreviewed. */

undefined4 FUN_4094d1e4(uint param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x3008;
      return 0;
    }
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    iVar2 = FUN_4094bc88(param_2,param_1,param_5);
    if (iVar2 == 0) {
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if (param_3 == 0x3083) {
        uVar4 = *(uint *)(*(int *)(iVar2 + 0xb8) + 0x5c);
        if (((uVar4 & 1) != 0) || ((uVar4 & 4) != 0)) {
          if (*(int *)(iVar2 + 0xf0) == 0x305c) {
            return 1;
          }
          if (*(int *)(iVar2 + 0xf4) == 0x305c) {
            return 1;
          }
          if (*(int *)(iVar2 + 0xc) != 1) {
            return 1;
          }
          *(int *)(iVar2 + 0xdc) = param_4;
          return 1;
        }
        if (param_5 == 0) {
          return 0;
        }
        uVar3 = 0x300c;
LAB_4094d388:
        *(undefined4 *)(param_5 + 0x10) = uVar3;
        return 0;
      }
      if (param_3 == 0x3093) {
        if (param_4 == 0x3094) {
          if ((*(uint *)(*(int *)(iVar2 + 0xb8) + 0x6c) & 0x400) == 0) {
LAB_4094d340:
            if (param_5 != 0) {
              *(undefined4 *)(param_5 + 0x10) = 0x3009;
              return 0;
            }
            return 0;
          }
LAB_4094d354:
          *(int *)(iVar2 + 0xe8) = param_4;
          return 1;
        }
        if (param_4 == 0x3095) goto LAB_4094d354;
      }
      else {
        if (param_3 != 0x3099) {
          if (param_5 == 0) {
            return 0;
          }
          uVar3 = 0x3004;
          goto LAB_4094d388;
        }
        if (param_4 == 0x309a) {
LAB_4094d2fc:
          *(int *)(iVar2 + 0xec) = param_4;
          return 1;
        }
        if (param_4 == 0x309b) {
          if ((*(uint *)(*(int *)(iVar2 + 0xb8) + 0x6c) & 0x200) == 0) goto LAB_4094d340;
          goto LAB_4094d2fc;
        }
      }
      if (param_5 == 0) {
        return 0;
      }
      uVar3 = 0x300c;
      goto LAB_4094d268;
    }
  }
  if (param_5 == 0) {
    return 0;
  }
  uVar3 = 0x3001;
LAB_4094d268:
  *(undefined4 *)(param_5 + 0x10) = uVar3;
  return 0;
}



/* 4094d3e0 FUN_4094d3e0 */

/* Boundary evidence: original MIPS .pdata 4094d3e0..4094d68b. Semantic name remains unreviewed. */

undefined4 FUN_4094d3e0(uint param_1,uint param_2,int param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    iVar2 = FUN_4094bc88(param_2,param_1,param_5);
    if (iVar2 == 0) {
      return 0;
    }
    if (param_4 == (undefined4 *)0x0) {
      if (param_5 == 0) {
        return 0;
      }
      *(undefined4 *)(param_5 + 0x10) = 0x300c;
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if (param_3 < 0x3087) {
        if (param_3 != 0x3086) {
          if (param_3 < 0x3081) {
            if (param_3 != 0x3080) {
              if (param_3 == 0x3028) {
                uVar3 = *(undefined4 *)(*(int *)(iVar2 + 0xb8) + 0x2c);
              }
              else {
                if (param_3 == 0x3056) {
                  uVar3 = *(undefined4 *)(iVar2 + 0xc0);
                  goto LAB_4094d660;
                }
                if (param_3 != 0x3057) {
                  if (param_3 != 0x3058) goto LAB_4094d614;
                  if (*(int *)(iVar2 + 0xc) != 1) {
                    return 1;
                  }
                  uVar3 = *(undefined4 *)(iVar2 + 0xd4);
                  goto LAB_4094d654;
                }
                uVar3 = *(undefined4 *)(iVar2 + 0xbc);
              }
LAB_4094d53c:
              *param_4 = uVar3;
              return 1;
            }
            if (*(int *)(iVar2 + 0xc) != 1) {
              return 1;
            }
            uVar3 = *(undefined4 *)(iVar2 + 0xf0);
          }
          else {
            if (param_3 == 0x3081) {
              if (*(int *)(iVar2 + 0xc) != 1) {
                return 1;
              }
              uVar3 = *(undefined4 *)(iVar2 + 0xf4);
              goto LAB_4094d53c;
            }
            if (param_3 == 0x3082) {
              if (*(int *)(iVar2 + 0xc) != 1) {
                return 1;
              }
              uVar3 = *(undefined4 *)(iVar2 + 0xd8);
              goto LAB_4094d660;
            }
            if (param_3 != 0x3083) {
LAB_4094d614:
              if (param_5 == 0) {
                return 0;
              }
              *(undefined4 *)(param_5 + 0x10) = 0x3004;
              return 0;
            }
            if (*(int *)(iVar2 + 0xc) != 1) {
              return 1;
            }
            uVar3 = *(undefined4 *)(iVar2 + 0xdc);
          }
LAB_4094d654:
          *param_4 = uVar3;
          return 1;
        }
        uVar3 = *(undefined4 *)(iVar2 + 0xe4);
      }
      else if (param_3 == 0x3087) {
        uVar3 = *(undefined4 *)(iVar2 + 0xcc);
      }
      else {
        if (param_3 == 0x3088) {
          uVar3 = *(undefined4 *)(iVar2 + 0xc4);
          goto LAB_4094d654;
        }
        if (param_3 == 0x3090) {
          uVar3 = *(undefined4 *)(iVar2 + 0xd0);
        }
        else {
          if (param_3 == 0x3091) {
            uVar3 = *(undefined4 *)(iVar2 + 0xf8);
            goto LAB_4094d654;
          }
          if (param_3 == 0x3092) {
            uVar3 = *(undefined4 *)(iVar2 + 0xe0);
          }
          else {
            if (param_3 == 0x3093) {
              uVar3 = *(undefined4 *)(iVar2 + 0xe8);
              goto LAB_4094d654;
            }
            if (param_3 != 0x3099) goto LAB_4094d614;
            uVar3 = *(undefined4 *)(iVar2 + 0xec);
          }
        }
      }
LAB_4094d660:
      *param_4 = uVar3;
      return 1;
    }
  }
  if (param_5 != 0) {
    *(undefined4 *)(param_5 + 0x10) = 0x3001;
  }
  return 0;
}



/* 4094d68c FUN_4094d68c */

/* Boundary evidence: original MIPS .pdata 4094d68c..4094d83f. Semantic name remains unreviewed. */

void FUN_4094d68c(undefined4 *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uStack00000010;
  
  FUN_40955a74();
  iVar6 = param_1[0x2f];
  uVar7 = param_1[0x30];
  bVar1 = false;
  bVar2 = true;
  iVar8 = 0;
  uVar9 = 0;
  uStack00000010 = param_2;
  iVar3 = iVar6;
  if ((param_1[0x3d] == 0x305f) && ((param_1[0x3c] == 0x305d || (param_1[0x3c] == 0x305e)))) {
    bVar1 = true;
  }
  while ((iVar3 != 1 && (uVar5 = param_1[0x30], uVar5 != 1))) {
    if (bVar1) {
      param_1[0x2f] = (uint)param_1[0x2f] >> 1;
      param_1[0x30] = uVar5 >> 1;
      iVar3 = FUN_4094a0a8(param_1,uStack00000010,*(undefined4 *)(*(int *)(param_3 + 8) + 0x1c));
      if (iVar3 == 1) break;
    }
    else {
      if (bVar2) {
        iVar6 = param_1[0x2f];
        iVar3 = iVar6 - iVar8;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 1;
        }
        iVar4 = uVar5 - uVar9;
        param_1[0x2f] = (iVar3 >> 1) + iVar8;
        if (iVar4 < 0) {
          iVar4 = iVar4 + 1;
        }
        param_1[0x30] = (iVar4 >> 1) + uVar9;
        uVar7 = uVar5;
        uVar5 = uVar9;
      }
      else {
        iVar8 = param_1[0x2f];
        param_1[0x2f] = ((uint)(iVar6 - iVar8) >> 1) + iVar8;
        param_1[0x30] = (uVar7 - uVar5 >> 1) + uVar5;
      }
      iVar3 = FUN_4094a0a8(param_1,uStack00000010,*(undefined4 *)(*(int *)(param_3 + 8) + 0x1c));
      uVar9 = uVar5;
      if (iVar3 == 1) {
        if (((uint)(iVar6 - param_1[0x2f]) < 9) && (uVar7 - param_1[0x30] < 9)) break;
        FUN_4094d014(param_1);
        bVar2 = false;
      }
      else {
        bVar2 = true;
        if ((iVar6 == iVar8) && (uVar7 == uVar5)) break;
      }
    }
    iVar3 = param_1[0x2f];
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955aac(0x18);
}



/* 4094d840 FUN_4094d840 */

/* Boundary evidence: original MIPS .pdata 4094d840..4094d90b. Semantic name remains unreviewed. */

uint FUN_4094d840(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2[3] == 0x30a0) {
    piVar3 = (int *)param_2[1];
  }
  else {
    if (param_2[3] != 0x30a1) {
      return 0;
    }
    piVar3 = (int *)*param_2;
  }
  if ((piVar3 != (int *)0x0) && (piVar3[3] != 0)) {
    if (param_1 == 0x3059) {
      uVar1 = FUN_4094bfcc(*piVar3,0,1);
      iVar2 = piVar3[1];
    }
    else {
      if (param_1 != 0x305a) {
        param_2[4] = 0x300c;
        return 0;
      }
      uVar1 = FUN_4094bfcc(*piVar3,0,1);
      iVar2 = piVar3[2];
    }
    uVar1 = FUN_4094bfcc(iVar2,uVar1,2);
    if (uVar1 != 0) {
      return uVar1 | 0x20000000;
    }
  }
  return 0;
}



/* 4094d90c FUN_4094d90c */

/* Boundary evidence: original MIPS .pdata 4094d90c..4094d993. Semantic name remains unreviewed. */

undefined4 FUN_4094d90c(uint param_1,undefined4 *param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  if (param_3 == 1) {
    param_2[0x2a] = 0;
  }
  iVar2 = param_2[0x27];
  param_2[0x27] = iVar2 + -1;
  if ((param_2[0x28] == 1) && (iVar2 + -1 == 0)) {
    param_2[0x27] = 1;
  }
  iVar2 = FUN_4094d09c(param_2,param_4);
  if (iVar2 == 0) {
    uVar1 = FUN_4094bd58((int)param_2,param_1,2,param_4,unaff_s1,unaff_s0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4094d994 FUN_4094d994 */

/* Boundary evidence: original MIPS .pdata 4094d994..4094dd17. Semantic name remains unreviewed. */

void FUN_4094d994(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  BOOL BVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uStack00000020;
  uint uStack00000024;
  HWND in_stack_00000058;
  HANDLE in_stack_0000005c;
  int *in_stack_00000060;
  undefined4 in_stack_00000068;
  
  FUN_40955a14();
  uStack00000020 = 0x1000;
  uStack00000024 = 0x1000;
  piVar4 = (int *)mali_sys_malloc(0x10c);
  if (piVar4 == (int *)0x0) {
    if (param_1 != (int *)0x0) {
      param_1[4] = 0x3003;
    }
    goto LAB_4094dd0c;
  }
  mali_sys_memset(piVar4,0,0x10c);
  FUN_4094cbfc((int)piVar4,param_4,&stack0x0000005c,param_3);
  if (param_3 == 0) {
    if (in_stack_00000058 == (HWND)0x0) {
      iVar5 = FUN_40949248();
      if (iVar5 != 0) {
        *piVar4 = iVar5;
        piVar4[0x29] = 1;
        goto LAB_4094da90;
      }
LAB_4094da2c:
      if (param_1 == (int *)0x0) goto LAB_4094da3c;
      iVar5 = 0x3003;
    }
    else {
      BVar6 = IsWindow(in_stack_00000058);
      if (BVar6 != 0) {
        iVar5 = FUN_4094b69c((int)in_stack_00000058);
        if (iVar5 != 1) {
          *piVar4 = (int)in_stack_00000058;
          goto LAB_4094da90;
        }
        goto LAB_4094da2c;
      }
      if (param_1 == (int *)0x0) goto LAB_4094da3c;
      iVar5 = 0x300b;
    }
LAB_4094da38:
    param_1[4] = iVar5;
  }
  else {
LAB_4094da90:
    iVar5 = FUN_4094cd1c((int)param_1,in_stack_00000060,param_4,(int)piVar4);
    if (iVar5 != 0) {
      if (param_3 == 0) {
        piVar4[0x38] = 1;
        piVar4[0x34] = 1;
        piVar4[0x3e] = 1;
        FUN_40948948(piVar4,(int *)&stack0x00000020,(int *)&stack0x00000024);
        uVar8 = uStack00000020;
        if (uStack00000020 == 0) {
          uVar8 = 1;
        }
        uVar9 = uStack00000024;
        if (uStack00000024 == 0) {
          uVar9 = 1;
        }
      }
      else if (param_3 == 2) {
        FUN_40948c54(in_stack_0000005c,&stack0x00000020,&stack0x00000024);
        uVar8 = uStack00000020;
        uVar9 = uStack00000024;
      }
      else {
        uVar8 = uStack00000020;
        uVar9 = uStack00000024;
        if (param_3 == 1) {
          iVar5 = piVar4[0x3c];
          if (iVar5 == 0x305c) {
            if (piVar4[0x3d] == 0x305c) {
LAB_4094dc2c:
              if ((((piVar4[0x3d] == 0x305f) && ((iVar5 == 0x305d || (iVar5 == 0x305e)))) &&
                  (((uStack00000020 - 1 & uStack00000020) != 0 ||
                   ((uStack00000024 - 1 & uStack00000024) != 0)))) &&
                 ((*(uint *)(param_4 + 0x5c) & 1) != 0)) {
                bVar2 = false;
                bVar3 = false;
                uVar10 = 1;
                uVar12 = 1;
LAB_4094dc98:
                uVar11 = uVar12;
                if (!bVar2) goto LAB_4094dcb0;
                if (!bVar3) goto LAB_4094dcd4;
              }
              goto LAB_4094db2c;
            }
          }
          else if (piVar4[0x3d] != 0x305c) goto LAB_4094dc2c;
          if (param_1 != (int *)0x0) {
            iVar5 = 0x3009;
            goto LAB_4094da38;
          }
          goto LAB_4094da3c;
        }
      }
LAB_4094db2c:
      piVar4[0x2f] = uVar8;
      piVar4[0x30] = uVar9;
      piVar4[0x2d] = param_2;
      iVar5 = FUN_4094a0a8(piVar4,in_stack_00000068,*(undefined4 *)(param_1[2] + 0x1c));
      if ((iVar5 == 0) &&
         ((piVar4[0x35] != 1 ||
          (iVar5 = FUN_4094d68c(piVar4,in_stack_00000068,(int)param_1), iVar5 == 0)))) {
LAB_4094dcf4:
        FUN_4094d09c(piVar4,param_1);
        param_1[4] = 0x3003;
      }
      else {
        if (param_3 == 0) {
          mali_frame_builder_use_surface_deps(piVar4[2],0);
        }
        iVar5 = 0;
        *(undefined2 *)(piVar4 + 0x1c) = 0;
        piVar4[0x1b] = 0;
        piVar1 = piVar4;
        do {
          piVar1[7] = 0;
          iVar7 = mali_ds_consumer_allocate
                            (*(undefined4 *)(param_1[2] + 0x1c),piVar1 + 5,FUN_4094d1c4,0);
          piVar1[9] = iVar7;
          if (iVar7 == 0) goto LAB_4094dcf4;
          iVar5 = iVar5 + 1;
          piVar1 = piVar1 + 5;
        } while (iVar5 < 4);
        piVar4[0x27] = 1;
      }
      goto LAB_4094dd0c;
    }
  }
LAB_4094da3c:
  FUN_4094d09c(piVar4,param_1);
LAB_4094dd0c:
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x28);
LAB_4094dcb0:
  uVar12 = uVar10 << 1;
  if (uVar8 <= uVar12) {
    bVar2 = true;
    uVar8 = uVar10;
  }
  uVar10 = uVar12;
  uVar12 = uVar11;
  if (!bVar3) {
LAB_4094dcd4:
    uVar12 = uVar11 << 1;
    if (uVar9 <= uVar12) {
      bVar3 = true;
      uVar9 = uVar11;
    }
  }
  goto LAB_4094dc98;
}



/* 4094dd18 FUN_4094dd18 */

/* Boundary evidence: original MIPS .pdata 4094dd18..4094ddfb. Semantic name remains unreviewed. */

undefined4 FUN_4094dd18(uint param_1,uint param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_3 != (int *)0x0) {
    iVar1 = FUN_4094bb8c(param_1);
    if (iVar1 == 0) {
      param_3[4] = 0x3008;
    }
    else {
      if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
        puVar2 = (undefined4 *)FUN_4094bc88(param_2,param_1,(int)param_3);
        if (puVar2 == (undefined4 *)0x0) {
          return 0;
        }
        if ((*(uint *)(iVar1 + 0x20) & 2) == 0) goto LAB_4094ddc4;
      }
      param_3[4] = 0x3001;
    }
    return 0;
  }
  puVar2 = (undefined4 *)FUN_4094ba2c(param_2,param_1);
LAB_4094ddc4:
  FUN_4094d90c(param_1,puVar2,1,param_3);
  return 1;
}



/* 4094ddfc FUN_4094ddfc */

/* Boundary evidence: original MIPS .pdata 4094ddfc..4094dff7. Semantic name remains unreviewed. */

uint FUN_4094ddfc(uint param_1,uint param_2,HANDLE param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined1 auStack_78 [88];
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_5 == (int *)0x0) {
      return 0;
    }
    param_5[4] = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    piVar2 = (int *)FUN_4094badc(param_2,param_1);
    if (piVar2 == (int *)0x0) {
      if (param_5 == (int *)0x0) {
        return 0;
      }
      param_5[4] = 0x3005;
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if ((piVar2[0x1b] & 2U) != 0) {
        iVar3 = GetObjectW(param_3,0x54,auStack_78);
        if (iVar3 == 0) {
          if (param_5 == (int *)0x0) {
            return 0;
          }
          iVar1 = 0x300a;
        }
        else {
          iVar3 = FUN_4094b600((int)param_3);
          if (iVar3 != 1) {
            iVar3 = FUN_40949fc8(param_3,piVar2);
            if (iVar3 == 0) {
              if (param_5 == (int *)0x0) {
                return 0;
              }
              iVar1 = 0x3009;
              goto LAB_4094dfcc;
            }
            puVar4 = (undefined4 *)FUN_4094d994(param_5,iVar1,2,(int)piVar2);
            if (puVar4 == (undefined4 *)0x0) {
              return 0;
            }
            iVar1 = FUN_4095044c((int)puVar4);
            if (((iVar1 != 0) && (uVar5 = FUN_4094c4ec((int)puVar4,param_1,2), uVar5 != 0)) &&
               ((uVar5 | 0x20000000) != 0)) {
              return uVar5 | 0x20000000;
            }
            puVar4[0x27] = 0;
            FUN_4094d09c(puVar4,param_5);
          }
          if (param_5 == (int *)0x0) {
            return 0;
          }
          iVar1 = 0x3003;
        }
LAB_4094dfcc:
        param_5[4] = iVar1;
        return 0;
      }
      if (param_5 == (int *)0x0) {
        return 0;
      }
      iVar1 = 0x3009;
      goto LAB_4094de78;
    }
  }
  if (param_5 == (int *)0x0) {
    return 0;
  }
  iVar1 = 0x3001;
LAB_4094de78:
  param_5[4] = iVar1;
  return 0;
}



/* 4094dff8 FUN_4094dff8 */

/* Boundary evidence: original MIPS .pdata 4094dff8..4094e187. Semantic name remains unreviewed. */

uint FUN_4094dff8(uint param_1,int param_2,int param_3,uint param_4,int *param_5,int *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_6 == (int *)0x0) {
      return 0;
    }
    param_6[4] = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    puVar2 = (undefined4 *)FUN_4094badc(param_4,param_1);
    if (puVar2 == (undefined4 *)0x0) {
      if (param_6 == (int *)0x0) {
        return 0;
      }
      param_6[4] = 0x3005;
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if (param_2 != 0x3096) {
        if (param_6 == (int *)0x0) {
          return 0;
        }
        param_6[4] = 0x300c;
        return 0;
      }
      if (param_3 == 0) {
        if (param_6 == (int *)0x0) {
          return 0;
        }
        iVar1 = 0x300c;
      }
      else {
        puVar2 = (undefined4 *)FUN_4094781c(iVar1,param_3,puVar2,param_5);
        if (puVar2 == (undefined4 *)0x0) {
          return 0;
        }
        uVar3 = FUN_4094c4ec((int)puVar2,param_1,2);
        if ((uVar3 != 0) && ((uVar3 | 0x20000000) != 0)) {
          return uVar3 | 0x20000000;
        }
        puVar2[0x27] = 0;
        FUN_4094d09c(puVar2,param_6);
        if (param_6 == (int *)0x0) {
          return 0;
        }
        iVar1 = 0x3003;
      }
      param_6[4] = iVar1;
      return 0;
    }
  }
  if (param_6 != (int *)0x0) {
    param_6[4] = 0x3001;
  }
  return 0;
}



/* 4094e188 FUN_4094e188 */

/* Boundary evidence: original MIPS .pdata 4094e188..4094e2df. Semantic name remains unreviewed. */

void FUN_4094e188(uint param_1,uint param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  FUN_40955ae4();
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_4 != (int *)0x0) {
      param_4[4] = 0x3008;
    }
    goto LAB_4094e2d8;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_4094e1e4:
    if (param_4 == (int *)0x0) goto LAB_4094e2d8;
    iVar1 = 0x3001;
  }
  else {
    iVar2 = FUN_4094badc(param_2,param_1);
    if (iVar2 == 0) {
      if (param_4 != (int *)0x0) {
        param_4[4] = 0x3005;
      }
      goto LAB_4094e2d8;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_4094e1e4;
    if ((*(uint *)(iVar2 + 0x6c) & 1) != 0) {
      puVar3 = (undefined4 *)FUN_4094d994(param_4,iVar1,1,iVar2);
      if ((puVar3 != (undefined4 *)0x0) &&
         ((uVar4 = FUN_4094c4ec((int)puVar3,param_1,2), uVar4 == 0 || ((uVar4 | 0x20000000) == 0))))
      {
        puVar3[0x27] = 0;
        FUN_4094d09c(puVar3,param_4);
        if (param_4 != (int *)0x0) {
          param_4[4] = 0x3003;
        }
      }
      goto LAB_4094e2d8;
    }
    if (param_4 == (int *)0x0) goto LAB_4094e2d8;
    iVar1 = 0x3009;
  }
  param_4[4] = iVar1;
LAB_4094e2d8:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x28);
}



/* 4094e2e0 FUN_4094e2e0 */

/* Boundary evidence: original MIPS .pdata 4094e2e0..4094e467. Semantic name remains unreviewed. */

uint FUN_4094e2e0(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_5 == (int *)0x0) {
      return 0;
    }
    param_5[4] = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    iVar2 = FUN_4094badc(param_2,param_1);
    if (iVar2 == 0) {
      if (param_5 == (int *)0x0) {
        return 0;
      }
      param_5[4] = 0x3005;
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if ((*(uint *)(iVar2 + 0x6c) & 4) != 0) {
        puVar3 = (undefined4 *)FUN_4094d994(param_5,iVar1,0,iVar2);
        if (puVar3 == (undefined4 *)0x0) {
          return 0;
        }
        uVar4 = FUN_4094c4ec((int)puVar3,param_1,2);
        if ((uVar4 != 0) && ((uVar4 | 0x20000000) != 0)) {
          return uVar4 | 0x20000000;
        }
        puVar3[0x27] = 0;
        FUN_4094d09c(puVar3,param_5);
        if (param_5 == (int *)0x0) {
          return 0;
        }
        param_5[4] = 0x3003;
        return 0;
      }
      if (param_5 == (int *)0x0) {
        return 0;
      }
      iVar1 = 0x3009;
      goto LAB_4094e35c;
    }
  }
  if (param_5 == (int *)0x0) {
    return 0;
  }
  iVar1 = 0x3001;
LAB_4094e35c:
  param_5[4] = iVar1;
  return 0;
}



/* 4094e468 FUN_4094e468 */

/* Boundary evidence: original MIPS .pdata 4094e468..4094e4fb. Semantic name remains unreviewed. */

undefined * FUN_4094e468(int param_1)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if (param_1 != 0) {
    ppuVar3 = &PTR_s_eglCreateImageKHR_4094386c;
    iVar2 = 0;
    do {
      iVar1 = mali_sys_strcmp(*ppuVar3,param_1);
      if (iVar1 == 0) {
        return (&PTR_eglCreateImageKHR_40943870)[iVar2 * 2];
      }
      iVar2 = iVar2 + 1;
      ppuVar3 = ppuVar3 + 2;
    } while (iVar2 < 3);
  }
  return (undefined *)0x0;
}



/* 4094e530 FUN_4094e530 */

/* Boundary evidence: original MIPS .pdata 4094e530..4094e54b. Semantic name remains unreviewed. */

void FUN_4094e530(void)

{
  mali_frame_builder_reset();
  return;
}



/* 4094e54c FUN_4094e54c */

/* Boundary evidence: original MIPS .pdata 4094e54c..4094e5af. Semantic name remains unreviewed. */

int FUN_4094e54c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = mali_frame_builder_flush(param_1,0,0);
  if (iVar1 == 0) {
    mali_frame_builder_wait(param_1);
    iVar1 = 0;
  }
  else {
    mali_frame_builder_reset();
  }
  return iVar1;
}



/* 4094e5b0 FUN_4094e5b0 */

/* Boundary evidence: original MIPS .pdata 4094e5b0..4094e5ef. Semantic name remains unreviewed. */

void FUN_4094e5b0(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  FUN_40955b34();
  uVar1 = 0;
  puVar2 = (undefined4 *)(param_2 + 0xc);
  do {
    mali_frame_builder_set_attachment(param_1,uVar1,*puVar2);
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 3);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094e5f0 FUN_4094e5f0 */

/* Boundary evidence: original MIPS .pdata 4094e5f0..4094e64b. Semantic name remains unreviewed. */

void FUN_4094e5f0(undefined4 param_1,int param_2)

{
  mali_frame_builder_set_attachment(param_1,0,*(undefined4 *)(param_2 + 0xc));
  mali_frame_builder_set_attachment(param_1,1,*(undefined4 *)(param_2 + 0x10));
  mali_frame_builder_set_attachment(param_1,2,*(undefined4 *)(param_2 + 0x14));
  return;
}



/* 4094e64c FUN_4094e64c */

/* Boundary evidence: original MIPS .pdata 4094e64c..4094e693. Semantic name remains unreviewed. */

void FUN_4094e64c(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  FUN_40955b34();
  uVar2 = 0;
  do {
    uVar1 = mali_frame_builder_get_attachment(param_1,uVar2);
    uVar2 = uVar2 + 1;
    param_2[3] = uVar1;
    *param_2 = 0;
    param_2 = param_2 + 1;
  } while (uVar2 < 3);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094e694 FUN_4094e694 */

/* Boundary evidence: original MIPS .pdata 4094e694..4094e7ab. Semantic name remains unreviewed. */

void FUN_4094e694(int param_1,int param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  FUN_40955ae4();
  uVar1 = *(ushort *)(param_1 + 0x70);
  iVar5 = (uVar1 + 1) * 0x14 + param_1;
  if ((param_3 == 1) && (iVar5 != 0)) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x72);
    uVar4 = uVar1 + 1;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if ((uVar3 == 0xffffffff) && (uVar4 == 0x80000000)) {
      trap(0x1800);
    }
    *(short *)(param_1 + 0x70) = (short)(uVar4 % uVar3);
    *(undefined4 *)(iVar5 + 8) = 1;
  }
  if (param_2 == 1) {
    iVar2 = mali_frame_builder_flush(*(undefined4 *)(param_1 + 8),param_4);
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0xe8) == 0x3095) {
        mali_frame_builder_wait(*(undefined4 *)(param_1 + 8));
      }
      if (param_3 == 1) {
        mali_frame_builder_reset(*(undefined4 *)(param_1 + 8));
      }
      goto LAB_4094e7a0;
    }
    if ((param_3 != 1) || (iVar5 == 0)) goto LAB_4094e7a0;
  }
  else {
    iVar2 = mali_frame_builder_swap(*(undefined4 *)(param_1 + 8),param_4,iVar5);
    if ((iVar2 == 0) || (mali_frame_builder_reset(*(undefined4 *)(param_1 + 8)), param_3 != 1))
    goto LAB_4094e7a0;
  }
  *(ushort *)(param_1 + 0x70) = uVar1;
  *(undefined4 *)(iVar5 + 8) = 0;
LAB_4094e7a0:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x10);
}



/* 4094e7ac FUN_4094e7ac */

/* Boundary evidence: original MIPS .pdata 4094e7ac..4094e9df. Semantic name remains unreviewed. */

int FUN_4094e7ac(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 local_38 [4];
  
  memset(local_38,0,0x10);
  iVar4 = *(int *)(param_2 + 100);
  if ((((iVar4 < 0) || (iVar4 < 2)) || (iVar4 == 4)) || (iVar4 != 0x10)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
  }
  iVar4 = mali_frame_builder_alloc(param_1,uVar5,4,1,0);
  if (iVar4 != 0) {
    uVar6 = 0;
    puVar7 = local_38;
    do {
      *puVar7 = *(undefined4 *)((param_3 - (int)local_38) + (int)puVar7);
      NKDbgPrintfW(L"__egl_mali_create_frame_builder::color_target[%d] == %08X\r\n",uVar6);
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar6 < 4);
    iVar1 = mali_render_attachment_alloc(local_38,4,1,uVar5,0);
    iVar2 = mali_render_attachment_alloc(0,0,0,uVar5,1);
    iVar3 = mali_render_attachment_alloc(0,0,0,uVar5,2);
    if (((iVar1 != 0) && (iVar2 != 0)) && (iVar3 != 0)) {
      mali_render_attachment_set_target(iVar1,0,local_38[0],0);
      mali_frame_builder_set_clear_value(iVar4,1,0xffffff,0);
      mali_frame_builder_set_clear_value(iVar4,2,0,0);
      mali_frame_builder_set_attachment(iVar4,0,iVar1);
      mali_frame_builder_set_attachment(iVar4,1,iVar2);
      mali_frame_builder_set_attachment(iVar4,2,iVar3);
      return iVar4;
    }
    mali_frame_builder_free(iVar4);
    if (iVar1 != 0) {
      mali_render_attachment_free(iVar1);
    }
    if (iVar2 != 0) {
      mali_render_attachment_free(iVar2);
    }
    if (iVar3 != 0) {
      mali_render_attachment_free(iVar3);
    }
  }
  return 0;
}



/* 4094e9e0 FUN_4094e9e0 */

/* Boundary evidence: original MIPS .pdata 4094e9e0..4094ea4f. Semantic name remains unreviewed. */

int FUN_4094e9e0(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 4094ea50 FUN_4094ea50 */

/* Boundary evidence: original MIPS .pdata 4094ea50..4094eaa7. Semantic name remains unreviewed. */

undefined4 FUN_4094ea50(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == -1) {
    if (param_1[1] == 0x3f) {
      uVar1 = 0;
    }
    else {
      uVar1 = __m200_texel_format_get_bpp();
    }
  }
  else {
    uVar1 = __mali_pixel_format_get_bpp(*param_1);
  }
  return uVar1;
}



/* 4094ead4 FUN_4094ead4 */

/* Boundary evidence: original MIPS .pdata 4094ead4..4094eb0b. Semantic name remains unreviewed. */

int FUN_4094ead4(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1[1] == 0) {
    iVar1 = mali_mem_mali_addr_get_full();
  }
  else {
    iVar1 = *param_1 + param_2;
  }
  return iVar1;
}



/* 4094eb0c FUN_4094eb0c */

/* Boundary evidence: original MIPS .pdata 4094eb0c..4094ee9f. Semantic name remains unreviewed. */

void FUN_4094eb0c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  
  FUN_40955a14();
  param_7 = 0xb08b06c0;
  param_8 = 0x438002c3;
  param_9 = 0x40010d00;
  param_10 = 0x1c08;
  uVar1 = mali_frame_builder_get_base_ctx(param_2);
  iVar2 = mali_mem_alloc(uVar1,0x10,0x40,0x34);
  if (iVar2 != 0) {
    mali_frame_builder_add_gp_job_mem(param_2,iVar2);
    mali_mem_write(iVar2,0,&param_7,0x10);
    if (*(int *)(iVar2 + 4) == 0) {
      mali_mem_mali_addr_get_full(iVar2,0);
    }
    iVar2 = mali_gp_job_add_vs_cmd(param_4);
    if ((iVar2 == 0) &&
       (puVar3 = (undefined4 *)mali_mem_alloc(uVar1,0xc,0x40,0x34), puVar3 != (undefined4 *)0x0)) {
      mali_frame_builder_add_gp_job_mem(param_2,puVar3);
      mali_mem_write(puVar3,0,param_3,0x24);
      iVar2 = mali_mem_alloc(uVar1,0x88,0x40,0x3c);
      if (iVar2 != 0) {
        mali_frame_builder_add_gp_job_mem(param_2,iVar2);
        puVar4 = (undefined4 *)mali_mem_ptr_map_area(iVar2,0,0x88,0x40);
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar3[1] == 0) {
            uVar1 = mali_mem_mali_addr_get_full(puVar3,0);
          }
          else {
            uVar1 = *puVar3;
          }
          *puVar4 = uVar1;
          puVar4[1] = 0x6002;
          piVar6 = (int *)param_1[2];
          if (piVar6[1] == 0) {
            iVar5 = mali_mem_mali_addr_get_full(piVar6,*param_1);
          }
          else {
            iVar5 = *piVar6 + *param_1;
          }
          puVar4[0x20] = iVar5;
          puVar4[0x21] = 0x8020;
          mali_mem_ptr_unmap_area(iVar2);
          if (*(int *)(iVar2 + 4) == 0) {
            mali_mem_mali_addr_get_full(iVar2,0);
          }
          iVar2 = mali_gp_job_add_vs_cmd(param_4);
          if (((((iVar2 == 0) && (iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0)) &&
               (iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0)) &&
              ((iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0 &&
               (iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0)))) &&
             (iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0)) {
            uVar1 = mali_frame_builder_get_gp_job(param_2);
            if (param_1[9] == 1) {
              iVar2 = mali_gp_job_add_plbu_cmd(uVar1);
              if (iVar2 != 0) goto LAB_4094ee98;
              param_1[9] = 0;
            }
            mali_frame_builder_get_tile_list_block_scale(param_2);
            iVar2 = mali_gp_job_add_plbu_cmd(uVar1);
            if (((iVar2 == 0) && (iVar2 = mali_gp_job_add_plbu_cmd(uVar1), iVar2 == 0)) &&
               (iVar2 = mali_gp_job_add_plbu_cmd(uVar1), iVar2 == 0)) {
              mali_gp_job_add_plbu_cmd(uVar1);
            }
          }
        }
      }
    }
  }
LAB_4094ee98:
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x28);
}



/* 4094eea0 FUN_4094eea0 */

/* Boundary evidence: original MIPS .pdata 4094eea0..4094efb3. Semantic name remains unreviewed. */

void FUN_4094eea0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  FUN_40955a14();
  iVar1 = mali_frame_builder_get_rsw_cache(param_2);
  iVar2 = __mali_rsw_cache_commit(iVar1,param_3,1);
  param_1[4] = iVar2;
  if (iVar2 == -1) {
    __mali_rsw_cache_flush(iVar1);
    uVar3 = mali_frame_builder_get_base_ctx(param_2);
    iVar2 = mali_mem_alloc(uVar3,0x4000,0x40,1);
    if (iVar2 != 0) {
      mali_frame_builder_add_frame_mem(param_2,iVar2);
      *(int *)(iVar1 + 4) = iVar2;
      iVar2 = __mali_rsw_cache_commit(iVar1,param_3,1);
      param_1[4] = iVar2;
      param_1[9] = 1;
      piVar4 = *(int **)(iVar1 + 4);
      if (piVar4[1] == 0) {
        iVar1 = mali_mem_mali_addr_get_full(piVar4,0);
      }
      else {
        iVar1 = *piVar4;
      }
      piVar4 = (int *)param_1[2];
      param_1[7] = iVar1;
      if (piVar4[1] == 0) {
        iVar1 = mali_mem_mali_addr_get_full(piVar4,*param_1);
      }
      else {
        iVar1 = *piVar4 + *param_1;
      }
      param_1[8] = iVar1 + param_1[6] * -0x10;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x10);
}



/* 4094efb4 FUN_4094efb4 */

/* Boundary evidence: original MIPS .pdata 4094efb4..4094f0a3. Semantic name remains unreviewed. */

undefined4 FUN_4094efb4(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  *param_1 = 0;
  param_1[1] = 0x40;
  uVar1 = mali_frame_builder_get_base_ctx(param_2);
  iVar2 = mali_mem_alloc(uVar1,0x70,0x40,9);
  param_1[3] = iVar2;
  param_1[2] = iVar2;
  if (iVar2 == 0) {
    *param_1 = 0;
    uVar1 = 0xffffffff;
    param_1[1] = 0;
  }
  else {
    mali_frame_builder_add_frame_mem(param_2,iVar2);
    param_1[6] = 0;
    iVar2 = mali_frame_builder_get_rsw_cache(param_2);
    param_1[9] = 1;
    piVar3 = *(int **)(iVar2 + 4);
    if (piVar3[1] == 0) {
      iVar2 = mali_mem_mali_addr_get_full(piVar3,0);
    }
    else {
      iVar2 = *piVar3;
    }
    piVar3 = (int *)param_1[2];
    param_1[7] = iVar2;
    if (piVar3[1] == 0) {
      iVar2 = mali_mem_mali_addr_get_full(piVar3,*param_1);
    }
    else {
      iVar2 = *piVar3 + *param_1;
    }
    param_1[8] = iVar2;
    uVar1 = 0;
  }
  return uVar1;
}



/* 4094f0a4 FUN_4094f0a4 */

/* Boundary evidence: original MIPS .pdata 4094f0a4..4094f1bf. Semantic name remains unreviewed. */

undefined4 FUN_4094f0a4(uint *param_1,int param_2)

{
  uint uVar1;
  
  m200_texture_descriptor_set_defaults(param_1);
  param_1[1] = param_1[1] & 0xfffffcff | 0x80;
  param_1[2] = param_1[2] | 0x1800;
  *param_1 = *param_1 & 0xffffff3f;
  uVar1 = mali_pixel_to_texel_format(*(undefined4 *)(*(int *)(param_2 + 0xb8) + 0x80));
  *param_1 = uVar1 | *param_1 & 0xffffffc0;
  param_1[2] = param_1[2] & 0x3fffff | *(int *)(param_2 + 0xbc) << 0x16;
  uVar1 = param_1[3] & 0xfffffff8 | *(uint *)(param_2 + 0xbc) >> 10;
  param_1[3] = uVar1;
  param_1[3] = *(int *)(param_2 + 0xc0) << 3 | uVar1 & 0xffff0007;
  param_1[6] = param_1[6] & 0xffff9fff;
  NKDbgPrintfW(L"%s %d\r\n",L"src/egl/egl_platform_win32.c",0x8d0);
  return 0xffffffff;
}



/* 4094f1c0 FUN_4094f1c0 */

/* Boundary evidence: original MIPS .pdata 4094f1c0..4094f413. Semantic name remains unreviewed. */

void FUN_4094f1c0(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
                 )

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  
  puVar1 = (undefined4 *)mali_render_attachment_get_target(param_2,param_5,0);
  m200_texture_descriptor_set_defaults(param_1);
  param_1[1] = param_1[1] & 0xfffffcff | 0x80;
  param_1[2] = param_1[2] | 0x1800;
  *param_1 = *param_1 & 0xffffff3f | (uint)(param_3 == 1) << 6;
  uVar6 = puVar1[6];
  if (uVar6 == 0x2c) {
    uVar6 = 0x32;
  }
  uVar4 = (uint)*(ushort *)(puVar1 + 3);
  uVar2 = FUN_4094ea50(puVar1 + 5);
  if ((uVar2 & 0xfffffff8) != 0) {
    uVar2 = FUN_4094ea50(puVar1 + 5);
    uVar4 = (uint)*(ushort *)(puVar1 + 4) / (uVar2 >> 3);
    if (uVar2 >> 3 == 0) {
      trap(0x1c00);
    }
  }
  *param_1 = *param_1 & 0xffffffc0 | uVar6;
  param_1[2] = param_1[2] & 0x3fffff | uVar4 << 0x16;
  uVar6 = (int)uVar4 >> 10 | param_1[3] & 0xfffffff8;
  param_1[3] = uVar6;
  param_1[3] = (uint)*(ushort *)((int)puVar1 + 0xe) << 3 | uVar6 & 0xffff0007;
  param_1[6] = puVar1[8] << 0xd | param_1[6] & 0xffff9fff;
  mali_surface_access_lock(puVar1);
  piVar5 = *(int **)*puVar1;
  if (piVar5[1] == 0) {
    iVar3 = mali_mem_mali_addr_get_full(piVar5,puVar1[1]);
  }
  else {
    iVar3 = *piVar5 + puVar1[1];
  }
  param_1[6] = (iVar3 << 0x18 ^ param_1[6]) & 0x3fffffff ^ iVar3 << 0x18;
  piVar5 = *(int **)*puVar1;
  if (piVar5[1] == 0) {
    uVar6 = mali_mem_mali_addr_get_full(piVar5,puVar1[1]);
  }
  else {
    uVar6 = *piVar5 + puVar1[1];
  }
  param_1[7] = param_1[7] & 0xff000000 | uVar6 >> 8;
  mali_surface_access_unlock(puVar1);
  return;
}



/* 4094f414 FUN_4094f414 */

/* Boundary evidence: original MIPS .pdata 4094f414..4094f463. Semantic name remains unreviewed. */

void FUN_4094f414(int *param_1)

{
  if (*param_1 != 0) {
    FUN_4094e9e0(*param_1);
  }
  if (param_1[3] != 0) {
    mali_render_attachment_free();
  }
  mali_sys_free(param_1);
  return;
}



/* 4094f464 FUN_4094f464 */

/* Boundary evidence: original MIPS .pdata 4094f464..4094f567. Semantic name remains unreviewed. */

void FUN_4094f464(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  FUN_40955a14();
  memset(&stack0x00000010,0,0x10);
  iVar1 = mali_frame_builder_get_attachment(param_1,0);
  iVar2 = mali_frame_builder_get_attachment(param_1,1);
  iVar3 = mali_frame_builder_get_attachment(param_1,2);
  uVar6 = 0;
  puVar7 = (undefined4 *)&stack0x00000010;
  do {
    mali_render_attachment_rotate_attachment(iVar1);
    uVar4 = mali_render_attachment_get_target(iVar1,0,0);
    *puVar7 = uVar4;
    NKDbgPrintfW(L"__egl_mali_destroy_frame_builder::color_target[%d] == %08X\r\n",uVar6,uVar4);
    uVar6 = uVar6 + 1;
    puVar7 = puVar7 + 1;
  } while (uVar6 < 4);
  if (iVar1 != 0) {
    mali_render_attachment_free(iVar1);
  }
  if (iVar2 != 0) {
    mali_render_attachment_free(iVar2);
  }
  if (iVar3 != 0) {
    mali_render_attachment_free(iVar3);
  }
  piVar5 = (int *)&stack0x00000010;
  iVar1 = 4;
  do {
    if (*piVar5 != 0) {
      FUN_4094e9e0(*piVar5);
    }
    iVar1 = iVar1 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar1 != 0);
  mali_frame_builder_free(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x20);
}



/* 4094f568 FUN_4094f568 */

/* Boundary evidence: original MIPS .pdata 4094f568..4094f6e7. Semantic name remains unreviewed. */

void FUN_4094f568(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 *puVar3;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  
  iVar1 = mali_frame_builder_get_supersample_factor(param_2);
  if (iVar1 == 2) {
    iVar1 = 3;
    puVar3 = param_3;
    do {
      uVar2 = __fpmul(*puVar3,0x40000000);
      *puVar3 = uVar2;
      uVar2 = __fpmul(puVar3[1],0x40000000);
      iVar1 = iVar1 + -1;
      puVar3[1] = uVar2;
      puVar3 = puVar3 + 3;
    } while (iVar1 != 0);
  }
  uVar2 = mali_frame_builder_get_gp_job(param_2);
  iVar1 = mali_gp_job_add_vs_cmd(uVar2);
  if ((iVar1 == 0) && (iVar1 = mali_gp_job_add_vs_cmd(uVar2), iVar1 == 0)) {
    uVar2 = mali_frame_builder_get_gp_job(param_2);
    iVar1 = mali_gp_job_add_plbu_cmd(uVar2);
    if (iVar1 == 0) {
      uVar2 = mali_frame_builder_get_gp_job(param_2);
      iVar1 = FUN_4094eb0c(param_1,param_2,param_3,uVar2,unaff_s5,unaff_s4,unaff_s3,unaff_s2,
                           unaff_s1,unaff_s0);
      if ((iVar1 == 0) && (iVar1 = mali_frame_builder_flush_gp(param_2,0,0), iVar1 == 0)) {
        uVar2 = mali_frame_builder_get_gp_job(param_2);
        iVar1 = mali_gp_job_add_vs_cmd(uVar2);
        if (iVar1 == 0) {
          uVar2 = mali_frame_builder_get_gp_job(param_2);
          mali_gp_job_add_plbu_cmd(uVar2);
        }
      }
    }
  }
  return;
}



/* 4094f6e8 FUN_4094f6e8 */

/* Boundary evidence: original MIPS .pdata 4094f6e8..4094f7c7. Semantic name remains unreviewed. */

int * FUN_4094f6e8(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = FUN_409519bc();
  piVar2 = (int *)mali_sys_malloc(0x18);
  if (piVar2 != (int *)0x0) {
    mali_sys_memset(piVar2,0,0x18);
    uVar3 = mali_render_attachment_get_target(*(undefined4 *)(param_2 + 0xc),0,0);
    uVar4 = mali_frame_builder_get_supersample_factor(param_1);
    iVar5 = mali_surface_alloc_surface(uVar3,0,piVar1[7]);
    *piVar2 = iVar5;
    if (iVar5 == 0) {
      mali_sys_free();
    }
    else {
      iVar5 = mali_render_attachment_alloc(piVar2,1,1,uVar4,0);
      piVar2[3] = iVar5;
      if (iVar5 != 0) {
        return piVar2;
      }
      FUN_4094f414(piVar2);
    }
  }
  return (int *)0x0;
}



/* 4094f7c8 FUN_4094f7c8 */

/* Boundary evidence: original MIPS .pdata 4094f7c8..4094f813. Semantic name remains unreviewed. */

void FUN_4094f7c8(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  uVar1 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
  FUN_409471b4(param_1,1,uVar1,param_4);
  return;
}



/* 4094f814 FUN_4094f814 */

/* Boundary evidence: original MIPS .pdata 4094f814..4094f873. Semantic name remains unreviewed. */

bool FUN_4094f814(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  
  if (*(int *)(param_2 + 0xc) == 0x30a0) {
    bVar1 = FUN_409481c4(param_1,param_2);
    iVar2 = CONCAT31(extraout_var,bVar1);
  }
  else {
    if (*(int *)(param_2 + 0xc) != 0x30a1) {
      return true;
    }
    bVar1 = FUN_4094735c(param_1,param_2);
    iVar2 = CONCAT31(extraout_var_00,bVar1);
  }
  return iVar2 == 1;
}



/* 4094f874 FUN_4094f874 */

/* Boundary evidence: original MIPS .pdata 4094f874..4094f8e3. Semantic name remains unreviewed. */

void FUN_4094f874(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_40955b34();
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar2 + 8) == 0x30a1) {
    piVar1 = FUN_409519bc();
    (**(code **)(piVar1[0xc] + 0xe8))(*(undefined4 *)(iVar2 + 0xc),param_2,param_3);
  }
  else if (*(int *)(iVar2 + 8) == 0x30a0) {
    FUN_40948468(iVar2,param_2,param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094f8e4 FUN_4094f8e4 */

/* Boundary evidence: original MIPS .pdata 4094f8e4..4094f92f. Semantic name remains unreviewed. */

void FUN_4094f8e4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_40955b34();
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar2 + 8) == 0x30a1) {
    piVar1 = FUN_409519bc();
    (**(code **)(piVar1[0xc] + 0xe4))(*(undefined4 *)(iVar2 + 0xc),param_2,param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094f930 FUN_4094f930 */

/* Boundary evidence: original MIPS .pdata 4094f930..4094f993. Semantic name remains unreviewed. */

void FUN_4094f930(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_40955b34();
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar2 + 8) == 0x30a1) {
    piVar1 = FUN_409519bc();
    (**(code **)(piVar1[0xc] + 0xe0))(*(undefined4 *)(iVar2 + 0xc),param_2,param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4094f994 FUN_4094f994 */

/* Boundary evidence: original MIPS .pdata 4094f994..4094fa4b. Semantic name remains unreviewed. */

void FUN_4094f994(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = FUN_409519bc();
  iVar2 = param_1[1];
  if (param_2 == 0) {
    (**(code **)(iVar2 + 0x100))
              (piVar1[7],**(undefined4 **)(iVar2 + 0xb4),iVar2,*param_1,
               *(undefined4 *)(iVar2 + 0xac));
  }
  puVar3 = param_1;
  if (((*(uint *)(iVar2 + 0x10) & 1) != 0) && ((*(uint *)(iVar2 + 0x10) & 2) == 0)) {
    puVar3 = *(undefined4 **)(iVar2 + 0x6c);
    *(undefined4 **)(iVar2 + 0x6c) = param_1;
  }
  param_1[2] = 0;
  if ((puVar3 != (undefined4 *)0x0) && (param_2 == 0)) {
    mali_ds_consumer_release_connections(puVar3[4],0,1,0);
  }
  return;
}



/* 4094fa4c FUN_4094fa4c */

/* Boundary evidence: original MIPS .pdata 4094fa4c..4094fa67. Semantic name remains unreviewed. */

void FUN_4094fa4c(undefined4 *param_1)

{
  FUN_4094f994(param_1,0);
  return;
}



/* 4094fa68 FUN_4094fa68 */

/* Boundary evidence: original MIPS .pdata 4094fa68..4095005f. Semantic name remains unreviewed. */

void FUN_4094fa68(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  uint in_stack_00000020;
  uint in_stack_00000024;
  undefined4 in_stack_00000028;
  uint in_stack_0000002c;
  uint in_stack_00000030;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint in_stack_00000040;
  uint in_stack_00000048;
  uint in_stack_0000004c;
  uint in_stack_00000050;
  uint in_stack_00000054;
  uint uStack00000058;
  undefined4 uStack0000005c;
  undefined4 uStack00000060;
  undefined4 uStack00000064;
  undefined4 uStack00000068;
  undefined4 uStack0000006c;
  undefined4 in_stack_00000070;
  undefined4 in_stack_00000074;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000088;
  undefined4 in_stack_0000008c;
  undefined4 in_stack_00000090;
  undefined4 uStack00000098;
  undefined4 uStack0000009c;
  undefined4 uStack000000a0;
  undefined4 uStack000000a4;
  undefined4 uStack000000a8;
  undefined4 uStack000000ac;
  undefined4 uStack000000b0;
  undefined4 uStack000000b4;
  undefined4 uStack000000b8;
  undefined4 uStack000000bc;
  undefined4 uStack000000c0;
  int in_stack_00000100;
  undefined4 in_stack_00000104;
  
  FUN_40955a74();
  uStack00000058 = 0x5e6;
  uStack00000068 = 0xe4e;
  uStack0000006c = 1999;
  uStack00000064 = 0x39001000;
  uStack000000a4 = 0x39001000;
  uStack000000a8 = 0x55e;
  uStack000000ac = 0x7ce;
  uVar8 = *(undefined4 *)(param_2 + 8);
  uStack00000098 = 0x22805c6;
  uStack0000005c = 0xf1003c20;
  uStack00000060 = 0;
  uStack0000009c = 0xf1003c20;
  uStack000000a0 = 0;
  uStack000000b0 = 0x9e5;
  uStack000000b4 = 0xffe40404;
  uStack000000b8 = 0;
  uStack000000bc = 0x39001001;
  uStack000000c0 = 0x3e400039;
  uVar1 = mali_frame_builder_get_base_ctx(uVar8);
  puVar2 = (uint *)mali_mem_alloc(uVar1,0x18,0x40,1);
  if (puVar2 == (uint *)0x0) goto LAB_40950054;
  mali_frame_builder_add_frame_mem(uVar8,puVar2);
  mali_mem_write(puVar2,0,&stack0x00000058,0x18);
  mali_sys_memset(&stack0x00000018,0,0x40);
  in_stack_0000004c = in_stack_0000004c & 0xffffffbf;
  in_stack_0000003c = uStack00000058 & 0x1f ^ in_stack_0000003c & 0xffffffe0;
  if (puVar2[1] == 0) {
    uVar3 = mali_mem_mali_addr_get_full(puVar2,0);
  }
  else {
    uVar3 = *puVar2;
  }
  in_stack_00000028 = 0xffff0000;
  in_stack_0000003c = in_stack_0000003c & 0x3f ^ uVar3;
  in_stack_00000038 = in_stack_00000038 & 0xffff0fff ^ 0xf000;
  in_stack_00000040 = in_stack_00000040 & 0xfffffff8 ^ 1;
  in_stack_00000050 = in_stack_00000050 & 0xffff;
  in_stack_0000004c = (in_stack_0000004c & 0xffffffe0 ^ 1) & 0xffffff7f;
  uVar1 = mali_frame_builder_get_base_ctx(uVar8);
  puVar2 = (uint *)mali_mem_alloc(uVar1,0x44,0x40,1);
  if (puVar2 == (uint *)0x0) goto LAB_40950054;
  mali_frame_builder_add_frame_mem(uVar8,puVar2);
  puVar4 = (uint *)mali_mem_ptr_map_area(puVar2,0,0x44,0);
  if (puVar4 == (uint *)0x0) goto LAB_40950054;
  if (in_stack_00000100 == 0) {
    iVar5 = FUN_4094f0a4(puVar4,param_2);
    if (iVar5 != 0) {
      mali_mem_ptr_unmap_area(puVar2);
      goto LAB_40950054;
    }
    if (puVar2[1] != 0) goto LAB_4094fccc;
LAB_4094fd68:
    uVar3 = mali_mem_mali_addr_get_full(puVar2,0);
LAB_4094fcd0:
    puVar4[0x10] = uVar3;
  }
  else if (in_stack_00000100 == 1) {
    FUN_4094f1c0(puVar4,param_4,0,0,in_stack_00000104);
    if (puVar2[1] == 0) goto LAB_4094fd68;
LAB_4094fccc:
    uVar3 = *puVar2;
    goto LAB_4094fcd0;
  }
  mali_mem_ptr_unmap_area(puVar2);
  in_stack_0000004c = in_stack_0000004c & 0xf0003fff ^ 0x4000;
  in_stack_00000048 = in_stack_00000048 & 0xfffffff0;
  if (puVar2[1] == 0) {
    uVar3 = mali_mem_mali_addr_get_full(puVar2,0x40);
  }
  else {
    uVar3 = *puVar2 + 0x40;
  }
  in_stack_00000048 = in_stack_00000048 & 0xf ^ uVar3;
  in_stack_00000038 = in_stack_00000038 & 0xfffffff8 ^ 7;
  in_stack_0000004c = in_stack_0000004c & 0xffffffdf ^ 0x20;
  in_stack_00000020 =
       (((((((((((in_stack_00000020 & 0xfffffff8 ^ 2) & 0xfffffe3f ^ 0xc0) & 0xfffffdff ^ 0x200) &
               0xffffc3ff ^ 0x1800) & 0xffff3fc7 ^ 0x10) & 0xfff8ffff ^ 0x30000) & 0xfff7ffff ^
           0x80000) & 0xff8fffff ^ 0x300000) & 0xef7fffff ^ 0x10000000) & 0xdfffffff ^ 0x20000000) &
        0xbfffffff ^ 0x40000000) & 0x7fffffff ^ 0x80000000;
  in_stack_00000024 = (in_stack_00000024 & 0xfffffff1 ^ 0xe) & 0xfffffffe;
  in_stack_0000002c = (in_stack_0000002c & 0xfffffff8 ^ 7) & 0xfffff007;
  in_stack_00000030 = (in_stack_00000030 & 0xfffffff8 ^ 7) & 0xfffff007;
  iVar5 = FUN_4094efb4(param_1,uVar8);
  if (iVar5 == 0) {
    piVar7 = (int *)param_1[2];
    if (piVar7[1] == 0) {
      uVar3 = mali_mem_mali_addr_get_full(piVar7,*param_1);
    }
    else {
      uVar3 = *piVar7 + *param_1;
    }
    in_stack_00000054 = in_stack_00000054 & 0xf ^ uVar3;
    in_stack_0000004c = in_stack_0000004c & 0xffffffe0 ^ 2;
    iVar5 = mali_render_attachment_get_target(param_4,in_stack_00000104,0);
    uVar6 = (uint)*(ushort *)(iVar5 + 0xc);
    uVar3 = FUN_4094ea50((int *)(iVar5 + 0x14));
    if ((uVar3 & 0xfffffff8) != 0) {
      uVar3 = FUN_4094ea50((int *)(iVar5 + 0x14));
      uVar6 = (uint)*(ushort *)(iVar5 + 0x10) / (uVar3 >> 3);
      if (uVar3 >> 3 == 0) {
        trap(0x1c00);
      }
    }
    in_stack_00000070 = __litofp(uVar6);
    in_stack_00000074 = 0;
    in_stack_00000078 = 0;
    in_stack_0000007c = 0;
    in_stack_00000080 = 0;
    in_stack_00000084 = 0;
    in_stack_00000088 = 0;
    in_stack_0000008c = __litofp(*(undefined2 *)(iVar5 + 0xe));
    in_stack_00000090 = 0;
    iVar5 = FUN_4094eea0(param_1,uVar8,&stack0x00000018);
    if (iVar5 == 0) {
      param_1[5] = 0;
      FUN_4094f568(param_1,uVar8,&stack0x00000070);
    }
  }
LAB_40950054:
                    /* WARNING: Subroutine does not return */
  FUN_40955aac(200);
}



/* 40950060 FUN_40950060 */

/* Boundary evidence: original MIPS .pdata 40950060..4095010f. Semantic name remains unreviewed. */

undefined4 FUN_40950060(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(int *)(*(int *)(param_3 + 0xc) + 8) == 0x30a1) {
    if (*(int *)(param_1 + 200) == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = FUN_4094e694(param_1,1,0,0);
      if ((iVar1 != 1) || (iVar1 = FUN_4094f7c8(param_1,1,param_2,param_3), iVar1 != 1)) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



/* 40950110 FUN_40950110 */

/* Boundary evidence: original MIPS .pdata 40950110..40950403. Semantic name remains unreviewed. */

void FUN_40950110(int param_1,uint param_2,uint param_3,int *param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,int param_8,int param_9)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  
  FUN_40955a74();
  param_8 = 0;
  param_9 = 0;
  iVar5 = 0;
  param_7 = 0;
  if (param_4[3] == 0x30a0) {
    iVar6 = param_4[1];
  }
  else {
    if (param_4[3] != 0x30a1) goto LAB_409503f8;
    iVar6 = *param_4;
  }
  if (((iVar6 == 0) || (param_2 == 0)) || (param_3 == 0)) goto LAB_409503f8;
  mali_frame_builder_wait(*(undefined4 *)(param_1 + 8));
  while ((*(int *)(param_1 + 0x1c) == 1 || (*(int *)(param_1 + 0x30) == 1))) {
    mali_sys_yield();
  }
  piVar7 = (int *)(param_1 + 0x24);
  iVar8 = 4;
  do {
    if (*piVar7 != 0) {
      mali_ds_consumer_release_connections(*piVar7,0,1,0x7fffffff);
    }
    *(undefined4 *)(param_1 + 0x6c) = 0;
    iVar8 = iVar8 + -1;
    piVar7 = piVar7 + 5;
  } while (iVar8 != 0);
  if (((*(uint *)(param_1 + 0x10) & 1) == 0) ||
     (iVar8 = param_8, iVar2 = param_9, (*(uint *)(param_1 + 0x10) & 2) != 0)) {
    iVar8 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
    uVar1 = mali_frame_builder_get_supersample_factor(*(undefined4 *)(param_1 + 8));
    iVar2 = mali_render_attachment_get_target(iVar8,0,0);
    param_7 = mali_surface_alloc(param_2 & 0xffff,param_3 & 0xffff,0,iVar2 + 0x14);
    iVar5 = mali_render_attachment_alloc(&param_7,1,1,uVar1);
    iVar3 = param_7;
    if (iVar5 != 0) {
      if (param_7 != 0) goto LAB_409502bc;
LAB_40950290:
      mali_render_attachment_free(iVar5);
      iVar3 = param_7;
    }
  }
  else {
LAB_409502bc:
    iVar3 = FUN_4094f930(iVar6,param_2,param_3);
    if (iVar3 == 0) {
      iVar3 = param_7;
      if (iVar5 != 0) goto LAB_40950290;
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x108) + 0x70) = 1;
      if (iVar5 != 0) {
        *(int *)(param_1 + 100) = iVar5;
      }
      if (((*(uint *)(param_1 + 0x10) & 1) == 0) && ((*(uint *)(param_1 + 0x10) & 2) == 0)) {
        uVar1 = *(undefined4 *)(param_1 + 100);
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x68);
      }
      mali_frame_builder_set_attachment(*(undefined4 *)(param_1 + 8),0,uVar1);
      *(uint *)(param_1 + 0xbc) = param_2;
      *(uint *)(param_1 + 0xc0) = param_3;
      uVar1 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
      uVar4 = mali_render_attachment_get_target(uVar1,0,0);
      *(undefined4 *)(param_1 + 0x14) = uVar4;
      *(int *)(param_1 + 0x18) = param_1;
      *(undefined2 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      uVar1 = mali_render_attachment_get_target(uVar1,1,0);
      *(undefined2 *)(param_1 + 0x72) = 2;
      *(undefined4 *)(param_1 + 0x28) = uVar1;
      *(int *)(param_1 + 0x2c) = param_1;
      *(undefined2 *)(param_1 + 0x34) = 1;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined2 *)(param_1 + 0x70) = 0;
      if ((*(uint *)(param_1 + 0x10) & 2) != 0) {
        mali_frame_builder_set_attachment
                  (*(undefined4 *)(param_1 + 8),0,*(undefined4 *)(param_1 + 100));
      }
      FUN_4094f874(iVar6,param_2,param_3);
      if ((((*(uint *)(param_1 + 0x10) & 1) != 0) && ((*(uint *)(param_1 + 0x10) & 2) == 0)) ||
         (iVar8 == 0)) goto LAB_409503f8;
      mali_render_attachment_free(iVar8);
      iVar3 = iVar2;
    }
  }
  if (iVar3 != 0) {
    FUN_4094e9e0(iVar3);
  }
LAB_409503f8:
                    /* WARNING: Subroutine does not return */
  FUN_40955aac(0x28);
}



/* 40950404 FUN_40950404 */

/* Boundary evidence: original MIPS .pdata 40950404..4095044b. Semantic name remains unreviewed. */

void FUN_40950404(int *param_1)

{
  int iVar1;
  
  iVar1 = mali_ds_connect_give_direct_ownership_and_flush
                    (param_1[4],*(undefined4 *)(*param_1 + 0x38),0);
  if (iVar1 != 0) {
    FUN_4094f994(param_1,1);
  }
  return;
}



/* 4095044c FUN_4095044c */

/* Boundary evidence: original MIPS .pdata 4095044c..4095066b. Semantic name remains unreviewed. */

undefined4 FUN_4095044c(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 auStack_40 [3];
  undefined4 local_34 [3];
  
  uVar5 = *(undefined4 *)(param_1 + 8);
  FUN_4094e64c(uVar5,auStack_40);
  piVar1 = FUN_4094f6e8(uVar5,(int)auStack_40);
  if (piVar1 != (int *)0x0) {
    FUN_4094e5f0(uVar5,(int)piVar1);
    iVar2 = mali_frame_builder_use(uVar5);
    if (iVar2 == 0) {
      iVar2 = FUN_4094e54c(uVar5);
      if (iVar2 == 0) {
        mali_frame_builder_reset(uVar5);
        uVar4 = 0;
        puVar6 = local_34;
        do {
          mali_frame_builder_set_attachment(uVar5,uVar4,*puVar6);
          uVar4 = uVar4 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar4 < 3);
        *(int *)(param_1 + 0x74) = 0;
        *(undefined4 *)(param_1 + 0x78) = 0;
        *(undefined4 *)(param_1 + 0x7c) = 0;
        *(undefined4 *)(param_1 + 0x80) = 0;
        *(undefined4 *)(param_1 + 0x84) = 0;
        *(undefined4 *)(param_1 + 0x88) = 0;
        *(undefined4 *)(param_1 + 0x8c) = 0;
        *(undefined4 *)(param_1 + 0x90) = 0;
        *(undefined4 *)(param_1 + 0x94) = 0;
        *(undefined4 *)(param_1 + 0x98) = 0;
        iVar2 = mali_frame_builder_write_lock(uVar5);
        if (iVar2 == 0) {
          iVar2 = mali_frame_builder_add_callback(uVar5,FUN_4094f414,piVar1);
          if (iVar2 != 0) {
            mali_frame_builder_write_unlock(uVar5);
            FUN_4094f414(piVar1);
            mali_frame_builder_reset(uVar5);
            return 0;
          }
          iVar2 = FUN_4094fa68((int *)(param_1 + 0x74),param_1,0,piVar1[3]);
          mali_frame_builder_write_unlock(uVar5);
          iVar3 = mali_frame_builder_flush(*(undefined4 *)(param_1 + 8),0,0);
          if (iVar3 != 0) {
            iVar2 = -1;
          }
          if (iVar2 != 0) {
            return 0;
          }
          return 1;
        }
      }
      else {
        uVar4 = 0;
        puVar6 = local_34;
        do {
          mali_frame_builder_set_attachment(uVar5,uVar4,*puVar6);
          uVar4 = uVar4 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar4 < 3);
      }
    }
    else {
      uVar4 = 0;
      puVar6 = local_34;
      do {
        mali_frame_builder_set_attachment(uVar5,uVar4,*puVar6);
        uVar4 = uVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar4 < 3);
    }
    FUN_4094f414(piVar1);
  }
  return 0;
}



/* 4095066c FUN_4095066c */

/* Boundary evidence: original MIPS .pdata 4095066c..40950713. Semantic name remains unreviewed. */

undefined4 FUN_4095066c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  iVar1 = mali_frame_builder_use(*(undefined4 *)(param_1 + 8));
  if ((iVar1 == 0) && (iVar1 = FUN_4094fa68((int *)(param_1 + 0x74),param_1,0,param_2), iVar1 == 0))
  {
    return 1;
  }
  return 0;
}



/* 40950714 FUN_40950714 */

/* Boundary evidence: original MIPS .pdata 40950714..409507d3. Semantic name remains unreviewed. */

void FUN_40950714(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iStack00000010;
  undefined4 *puStack00000014;
  
  FUN_40955ae4();
  iStack00000010 = param_3;
  puStack00000014 = param_4;
  iVar1 = FUN_4094e694(param_1,1,0,0);
  if (iVar1 == 1) {
    uVar2 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
    uVar2 = mali_render_attachment_get_target(uVar2,0,0);
    iStack00000010 = param_2;
    (**(code **)(param_1 + 0x104))
              (*(undefined4 *)(*(int *)(param_3 + 8) + 0x1c),*(undefined4 *)*param_4,param_1,uVar2);
    FUN_4095044c(param_1);
    FUN_4094f814(param_1,param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 409507d4 FUN_409507d4 */

/* Boundary evidence: original MIPS .pdata 409507d4..4095095f. Semantic name remains unreviewed. */

undefined4 FUN_409507d4(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined4 uVar5;
  int unaff_s5;
  int *piVar6;
  uint in_stack_ffffffd8;
  uint in_stack_ffffffdc;
  
  uVar5 = 0;
  if ((param_1[4] & 2) != 0) {
    uVar2 = mali_render_attachment_get_target(param_1[0x1a],0,0);
    uVar5 = mali_frame_builder_get_attachment(param_1[2],0);
    mali_frame_builder_set_attachment(param_1[2],0,param_1[0x1a]);
    param_1[(*(ushort *)(param_1 + 0x1c) + 1) * 5] = uVar2;
    mali_frame_builder_use(param_1[2]);
  }
  uVar2 = mali_frame_builder_get_attachment(param_1[2],0);
  piVar6 = param_2;
  uVar3 = FUN_4094e694((int)param_1,0,1,FUN_40950404);
  if ((param_1[0x3a] == 0x3094) && (iVar4 = FUN_4095066c((int)param_1,uVar2), iVar4 == 0)) {
    uVar3 = 0;
  }
  if ((param_1[4] & 2) != 0) {
    mali_frame_builder_set_attachment(param_1[2],0,uVar5);
  }
  FUN_40948948(param_1,(int *)&stack0xffffffdc,(int *)&stack0xffffffd8);
  if (((in_stack_ffffffdc != param_1[0x2f]) || (in_stack_ffffffd8 != param_1[0x30])) &&
     (iVar4 = FUN_40950110((int)param_1,in_stack_ffffffdc,in_stack_ffffffd8,param_2,piVar6,param_3,
                           in_stack_ffffffd8,in_stack_ffffffdc,unaff_s5), iVar4 == 0)) {
    uVar3 = 0;
  }
  bVar1 = FUN_4094f814((int)param_1,(int)param_2);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar3 = 0;
  }
  return uVar3;
}



/* 4095097c FUN_4095097c */

/* Boundary evidence: original MIPS .pdata 4095097c..409509e3. Semantic name remains unreviewed. */

undefined * FUN_4095097c(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined *)0x0;
  }
  else {
    puVar1 = (undefined *)FUN_40947d74(param_2,param_1);
    if ((puVar1 == (undefined *)0x0) &&
       (puVar1 = (undefined *)FUN_40947218(param_2,param_1), puVar1 == (undefined *)0x0)) {
      puVar1 = FUN_4094e468(param_1);
    }
  }
  return puVar1;
}



/* 409509e4 FUN_409509e4 */

/* Boundary evidence: original MIPS .pdata 409509e4..40950a77. Semantic name remains unreviewed. */

undefined4 FUN_409509e4(undefined4 *param_1)

{
  int *piVar1;
  int local_10 [2];
  
  FUN_4094c80c(param_1,local_10);
  if (local_10[0] == 0x30a0) {
    if (param_1[7] == 0) {
      return 0;
    }
    FUN_40947fbc((int)param_1);
  }
  else if (local_10[0] == 0x30a1) {
    if (param_1[6] == 0) {
      return 0;
    }
    piVar1 = FUN_409519bc();
    (**(code **)(piVar1[0xc] + 0xf4))(param_1[6]);
  }
  return 1;
}



/* 40950a78 FUN_40950a78 */

/* Boundary evidence: original MIPS .pdata 40950a78..40950c17. Semantic name remains unreviewed. */

void FUN_40950a78(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  FUN_40955ae4();
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_4 != 0) {
      *(undefined4 *)(param_4 + 0x10) = 0x3008;
    }
    goto LAB_40950c10;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_40950adc:
    if (param_4 == 0) goto LAB_40950c10;
    uVar3 = 0x3001;
  }
  else {
    iVar2 = FUN_4094bc88(param_2,param_1,param_4);
    if (iVar2 == 0) goto LAB_40950c10;
    if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_40950adc;
    if (param_3 != 0x3084) {
      if (param_4 == 0) goto LAB_40950c10;
      uVar3 = 0x300c;
LAB_40950b34:
      *(undefined4 *)(param_4 + 0x10) = uVar3;
      goto LAB_40950c10;
    }
    if ((*(uint *)(iVar2 + 0xc) & 1) == 0) {
      if (param_4 == 0) goto LAB_40950c10;
      uVar3 = 0x300d;
    }
    else {
      uVar4 = *(uint *)(*(int *)(iVar2 + 0xb8) + 0x5c);
      if (((uVar4 & 1) == 0) && ((uVar4 & 4) == 0)) {
        if (param_4 != 0) {
          *(undefined4 *)(param_4 + 0x10) = 0x300d;
        }
        goto LAB_40950c10;
      }
      if (*(int *)(iVar2 + 0xf0) != 0x305c) {
        if (*(int *)(iVar2 + 0xfc) == 0) {
          if (param_4 == 0) goto LAB_40950c10;
          uVar3 = 0x3002;
        }
        else {
          if (*(int *)(param_4 + 4) != 0) {
            iVar1 = *(int *)(*(int *)(param_4 + 4) + 0xc);
            (**(code **)(*(int *)(iVar1 + 0x18) * 0x4c + *(int *)(*(int *)(param_4 + 8) + 0x30) + -4
                        ))(*(undefined4 *)(iVar1 + 0xc));
            *(undefined4 *)(iVar2 + 0xfc) = 0;
            goto LAB_40950c10;
          }
          uVar3 = 0x3006;
        }
        goto LAB_40950b34;
      }
      if (param_4 == 0) goto LAB_40950c10;
      uVar3 = 0x3009;
    }
  }
  *(undefined4 *)(param_4 + 0x10) = uVar3;
LAB_40950c10:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x10);
}



/* 40950c18 FUN_40950c18 */

/* Boundary evidence: original MIPS .pdata 40950c18..40950d1b. Semantic name remains unreviewed. */

undefined4 FUN_40950c18(uint param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    param_3[4] = 0x3008;
    return 0;
  }
  if (((*(uint *)(iVar1 + 0x20) & 1) == 0) || ((*(uint *)(iVar1 + 0x20) & 2) != 0)) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    param_3[4] = 0x3001;
    return 0;
  }
  if (param_3[3] == 0x30a0) {
    iVar1 = param_3[1];
  }
  else {
    if (param_3[3] != 0x30a1) goto LAB_40950cfc;
    iVar1 = *param_3;
  }
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0xb8);
    iVar2 = *(int *)(iVar3 + 0x4c);
    if ((param_2 < iVar2) || (iVar2 = *(int *)(iVar3 + 0x48), iVar2 < param_2)) {
      param_2 = iVar2;
    }
    *(int *)(*(int *)(iVar1 + 4) + 0xac) = param_2;
    return 1;
  }
LAB_40950cfc:
  param_3[4] = 0x3006;
  return 0;
}



/* 40950d1c FUN_40950d1c */

/* Boundary evidence: original MIPS .pdata 40950d1c..40950ed7. Semantic name remains unreviewed. */

void FUN_40950d1c(uint param_1,uint param_2,HANDLE param_3,undefined4 *param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  FUN_40955ae4();
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_4 != (undefined4 *)0x0) {
      param_4[4] = 0x3008;
    }
    goto LAB_40950ecc;
  }
  if (((*(uint *)(iVar1 + 0x20) & 1) == 0) || ((*(uint *)(iVar1 + 0x20) & 2) != 0)) {
    if (param_4 != (undefined4 *)0x0) {
      param_4[4] = 0x3001;
    }
    goto LAB_40950ecc;
  }
  iVar1 = GetObjectW(param_3,0x54,&stack0x00000020);
  if (iVar1 == 0) {
    if (param_4 == (undefined4 *)0x0) goto LAB_40950ecc;
    uVar5 = 0x300a;
  }
  else {
    iVar1 = FUN_4094bc88(param_2,param_1,(int)param_4);
    if (iVar1 == 0) goto LAB_40950ecc;
    puVar2 = (undefined4 *)FUN_4094c80c(param_4,&param_7);
    if ((puVar2 != (undefined4 *)0x0) && (puVar2[3] != 0)) {
      if (*(int *)(puVar2[3] + 0x20) == 1) {
        if (param_4 == (undefined4 *)0x0) goto LAB_40950ecc;
        uVar5 = 0x300e;
      }
      else {
        if (puVar2[1] == iVar1) {
          iVar3 = FUN_40948bac(param_3,iVar1);
          if (iVar3 == 0) {
            if (param_4 == (undefined4 *)0x0) goto LAB_40950ecc;
            uVar5 = 0x3009;
          }
          else {
            if (param_7 == 0x30a1) {
              piVar4 = FUN_409519bc();
              (**(code **)(piVar4[0xc] + 0xf0))(param_4[6]);
            }
            iVar1 = FUN_40950714(iVar1,param_3,(int)param_4,puVar2);
            if ((iVar1 != 0) || (param_4 == (undefined4 *)0x0)) goto LAB_40950ecc;
            uVar5 = 0x3003;
          }
          goto LAB_40950ec4;
        }
        if (param_4 == (undefined4 *)0x0) goto LAB_40950ecc;
        uVar5 = 0x300d;
      }
      param_4[4] = uVar5;
      goto LAB_40950ecc;
    }
    if (param_4 == (undefined4 *)0x0) goto LAB_40950ecc;
    uVar5 = 0x3006;
  }
LAB_40950ec4:
  param_4[4] = uVar5;
LAB_40950ecc:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x78);
}



/* 40950ed8 FUN_40950ed8 */

/* Boundary evidence: original MIPS .pdata 40950ed8..409510a7. Semantic name remains unreviewed. */

undefined4 FUN_40950ed8(uint param_1,uint param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int local_20 [2];
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    param_3[4] = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    puVar2 = (undefined4 *)FUN_4094bc88(param_2,param_1,(int)param_3);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      iVar1 = FUN_4094c80c(param_3,local_20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
        if (*(int *)(*(int *)(iVar1 + 0xc) + 0x20) == 1) {
          if (param_3 == (int *)0x0) {
            return 0;
          }
          iVar1 = 0x300e;
        }
        else {
          if (*(undefined4 **)(iVar1 + 4) == puVar2) {
            if (puVar2[3] == 1) {
              return 1;
            }
            if (puVar2[3] == 2) {
              return 1;
            }
            if (puVar2[0x39] == 0x3085) {
              return 1;
            }
            if (local_20[0] == 0x30a0) {
              FUN_40948008((int)param_3);
            }
            else if (local_20[0] == 0x30a1) {
              piVar3 = FUN_409519bc();
              (**(code **)(piVar3[0xc] + 0xf0))(param_3[6]);
            }
            iVar1 = FUN_409507d4(puVar2,param_3,iVar1);
            if (iVar1 != 0) {
              return 1;
            }
            if (param_3 == (int *)0x0) {
              return 0;
            }
            iVar1 = 0x3003;
            goto LAB_40951080;
          }
          if (param_3 == (int *)0x0) {
            return 0;
          }
          iVar1 = 0x300d;
        }
        param_3[4] = iVar1;
        return 0;
      }
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iVar1 = 0x3006;
LAB_40951080:
      param_3[4] = iVar1;
      return 0;
    }
  }
  if (param_3 != (int *)0x0) {
    param_3[4] = 0x3001;
  }
  return 0;
}



/* 409510a8 FUN_409510a8 */

/* Boundary evidence: original MIPS .pdata 409510a8..409511df. Semantic name remains unreviewed. */

undefined4 FUN_409510a8(int param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  
  if (param_2[3] == 0x30a0) {
    iVar2 = param_2[1];
  }
  else {
    if (param_2[3] != 0x30a1) {
      return 1;
    }
    iVar2 = *param_2;
  }
  if (((iVar2 == 0) || (*(int *)(iVar2 + 0xc) == 0)) || (*(int *)(*(int *)(iVar2 + 4) + 0xc) != 2))
  {
    return 1;
  }
  if (param_1 == 0x305b) {
    iVar2 = FUN_4095044c(*(int *)(iVar2 + 4));
    if ((iVar2 != 0) &&
       (((param_2[3] != 0x30a1 || (iVar2 = *param_2, iVar2 == 0)) ||
        ((*(int *)(iVar2 + 0xc) == 0 ||
         (bVar1 = FUN_4094735c(*(int *)(iVar2 + 4),(int)param_2), CONCAT31(extraout_var,bVar1) != 0)
         ))))) {
      if (param_2[3] != 0x30a0) {
        return 1;
      }
      iVar2 = param_2[1];
      if (iVar2 == 0) {
        return 1;
      }
      if (*(int *)(iVar2 + 0xc) == 0) {
        return 1;
      }
      bVar1 = FUN_409481c4(*(int *)(iVar2 + 4),(int)param_2);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        return 1;
      }
    }
    iVar2 = 0x3003;
  }
  else {
    iVar2 = 0x300c;
  }
  param_2[4] = iVar2;
  return 0;
}



/* 409511e0 FUN_409511e0 */

/* Boundary evidence: original MIPS .pdata 409511e0..4095128f. Semantic name remains unreviewed. */

void FUN_409511e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_40955b34();
  puVar1 = (undefined4 *)FUN_4094c80c(param_1,(undefined4 *)&stack0x00000018);
  if ((((puVar1 != (undefined4 *)0x0) && (puVar1[3] != 0)) && (*(int *)(puVar1[3] + 0xc) != 0)) &&
     (((iVar2 = FUN_409509e4(param_1), iVar2 == 1 && (iVar2 = puVar1[1], *(int *)(iVar2 + 0xc) == 2)
       ) && ((iVar2 = FUN_40950714(iVar2,*(undefined4 *)(iVar2 + 4),(int)param_1,puVar1), iVar2 == 0
             && (param_1 != (undefined4 *)0x0)))))) {
    param_1[4] = 0x3003;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x20);
}



/* 40951290 FUN_40951290 */

/* Boundary evidence: original MIPS .pdata 40951290..40951423. Semantic name remains unreviewed. */

char * FUN_40951290(uint param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = FUN_409519bc();
  iVar2 = FUN_4094bb8c(param_1);
  if (iVar2 == 0) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3008;
    }
  }
  else if (((*(uint *)(iVar2 + 0x20) & 1) == 0) || ((*(uint *)(iVar2 + 0x20) & 2) != 0)) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3001;
    }
  }
  else {
    if (param_2 == 0x3053) {
      return "ARM";
    }
    if (param_2 == 0x3054) {
      return "1.4 WindowsCE-r1p1-05rel0";
    }
    if (param_2 == 0x3055) {
      uVar3 = *(uint *)(piVar1[0xc] + 0x10c);
      if ((uVar3 & 5) == 5) {
        return 
        "EGL_KHR_image EGL_KHR_image_base EGL_KHR_image_pixmap EGL_KHR_vg_parent_image EGL_KHR_gl_texture_2D_image EGL_KHR_gl_texture_cubemap_image EGL_KHR_gl_renderbuffer_image "
        ;
      }
      if ((uVar3 & 1) == 0) {
        if ((uVar3 & 4) != 0) {
          return 
          "EGL_KHR_image EGL_KHR_image_base EGL_KHR_image_pixmap EGL_KHR_vg_parent_image EGL_KHR_gl_texture_2D_image EGL_KHR_gl_texture_cubemap_image EGL_KHR_gl_renderbuffer_image "
          ;
        }
        if ((uVar3 & 2) == 0) {
          return "";
        }
      }
      return 
      "EGL_KHR_image EGL_KHR_image_base EGL_KHR_image_pixmap EGL_KHR_vg_parent_image EGL_KHR_gl_texture_2D_image "
      ;
    }
    if (param_2 == 0x308d) {
      return "OpenGL_ES OpenVG";
    }
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x300c;
    }
  }
  return (char *)0x0;
}



/* 40951424 FUN_40951424 */

/* Boundary evidence: original MIPS .pdata 40951424..409514b3. Semantic name remains unreviewed. */

undefined4 FUN_40951424(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1[7] == 0) {
    uVar2 = 1;
  }
  else {
    iVar3 = param_1[3];
    iVar1 = FUN_40952154(0x30a0,param_1);
    if (iVar1 == 1) {
      uVar2 = FUN_409511e0(param_1);
      iVar1 = FUN_40952154(iVar3,param_1);
      if (iVar1 == 1) {
        return uVar2;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 409514b4 FUN_409514b4 */

/* Boundary evidence: original MIPS .pdata 409514b4..40951637. Semantic name remains unreviewed. */

void FUN_409514b4(uint param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40955ae4();
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_4 != (int *)0x0) {
      param_4[4] = 0x3008;
    }
    goto LAB_4095162c;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_40951518:
    if (param_4 == (int *)0x0) goto LAB_4095162c;
    iVar1 = 0x3001;
LAB_40951524:
    param_4[4] = iVar1;
  }
  else {
    iVar2 = FUN_4094bc88(param_2,param_1,(int)param_4);
    if (iVar2 == 0) goto LAB_4095162c;
    if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_40951518;
    if (param_3 == 0x3084) {
      if (*(int *)(iVar2 + 0xfc) != 1) {
        if ((*(uint *)(iVar2 + 0xc) & 1) == 0) {
          if (param_4 == (int *)0x0) goto LAB_4095162c;
          iVar1 = 0x300d;
        }
        else {
          uVar3 = *(uint *)(*(int *)(iVar2 + 0xb8) + 0x5c);
          if (((uVar3 & 1) == 0) && ((uVar3 & 4) == 0)) {
            if (param_4 != (int *)0x0) {
              param_4[4] = 0x300d;
            }
            goto LAB_4095162c;
          }
          if (*(int *)(iVar2 + 0xf0) != 0x305c) {
            uVar3 = FUN_409523e0(param_4);
            if (uVar3 != 0) {
              FUN_40948054(iVar2,(int)param_4);
            }
            goto LAB_4095162c;
          }
          if (param_4 == (int *)0x0) goto LAB_4095162c;
          iVar1 = 0x3009;
        }
        goto LAB_40951524;
      }
      if (param_4 == (int *)0x0) goto LAB_4095162c;
      iVar1 = 0x3002;
    }
    else {
      if (param_4 == (int *)0x0) goto LAB_4095162c;
      iVar1 = 0x300c;
    }
    param_4[4] = iVar1;
  }
LAB_4095162c:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x10);
}



/* 40951638 FUN_40951638 */

/* Boundary evidence: original MIPS .pdata 40951638..409517e3. Semantic name remains unreviewed. */

void FUN_40951638(void)

{
  int *piVar1;
  int iVar2;
  undefined4 local_18 [2];
  
  local_18[0] = 0;
  if (DAT_40958af0 != (int *)0x0) {
    piVar1 = DAT_40958af0;
    if (*DAT_40958af0 != 0) {
      __mali_named_list_free(*DAT_40958af0,0);
      piVar1 = DAT_40958af0;
      *DAT_40958af0 = 0;
    }
    iVar2 = piVar1[2];
    if (iVar2 != 0) {
      while (piVar1 = (int *)__mali_named_list_iterate_begin(iVar2,local_18), piVar1 != (int *)0x0)
      {
        if (piVar1[1] != 0) {
          mali_sys_free();
        }
        if (*piVar1 != 0) {
          mali_sys_free();
        }
        __mali_named_list_remove(DAT_40958af0[2],piVar1[5]);
        mali_sys_free(piVar1);
        iVar2 = DAT_40958af0[2];
      }
      __mali_named_list_free(DAT_40958af0[2],0);
      piVar1 = DAT_40958af0;
      DAT_40958af0[2] = 0;
    }
    if (piVar1[5] != 0) {
      mali_sys_lock_try_lock(piVar1[5]);
      mali_sys_lock_unlock(DAT_40958af0[5]);
      mali_sys_lock_destroy(DAT_40958af0[5]);
      piVar1 = DAT_40958af0;
      DAT_40958af0[5] = 0;
    }
    if (piVar1[6] != 0) {
      mali_sys_mutex_try_lock(piVar1[6]);
      mali_sys_mutex_unlock(DAT_40958af0[6]);
      mali_sys_mutex_destroy(DAT_40958af0[6]);
      piVar1 = DAT_40958af0;
      DAT_40958af0[6] = 0;
    }
    if (piVar1[0xc] != 0) {
      FUN_40947ca0((int)piVar1);
      piVar1 = DAT_40958af0;
    }
    if ((undefined4 *)piVar1[0xc] != (undefined4 *)0x0) {
      FUN_40946274((undefined4 *)piVar1[0xc]);
      mali_sys_free(DAT_40958af0[0xc]);
      piVar1 = DAT_40958af0;
    }
    if (piVar1[0x12] != 0) {
      __mali_named_list_free(piVar1[0x12],0);
      piVar1 = DAT_40958af0;
    }
    mali_sys_free(piVar1);
    DAT_40958af0 = (int *)0x0;
  }
  return;
}



/* 409517e4 FUN_409517e4 */

/* Boundary evidence: original MIPS .pdata 409517e4..409518f7. Semantic name remains unreviewed. */

void FUN_409517e4(void)

{
  int iVar1;
  
  iVar1 = DAT_40958af0;
  if ((*(int *)(DAT_40958af0 + 0x34) != 0) && (*(int *)(DAT_40958af0 + 0x30) != 0)) {
    (**(code **)(*(int *)(DAT_40958af0 + 0x30) + 0xd4))();
    *(undefined4 *)(DAT_40958af0 + 0x34) = 0;
  }
  if ((*(uint *)(iVar1 + 0x2c) & 8) != 0) {
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffff7;
  }
  if ((*(uint *)(iVar1 + 0x2c) & 4) != 0) {
    mali_gp_close(*(undefined4 *)(iVar1 + 0x1c));
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffb;
  }
  if ((*(uint *)(iVar1 + 0x2c) & 2) != 0) {
    mali_pp_close(*(undefined4 *)(iVar1 + 0x1c));
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffd;
  }
  if ((*(uint *)(iVar1 + 0x2c) & 1) != 0) {
    mali_mem_close(*(undefined4 *)(iVar1 + 0x1c));
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffe;
  }
  if (*(int *)(iVar1 + 0x1c) != 0) {
    mali_base_context_destroy();
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  return;
}



/* 409518f8 FUN_409518f8 */

/* Boundary evidence: original MIPS .pdata 409518f8..4095198f. Semantic name remains unreviewed. */

void FUN_409518f8(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_40958af0;
  *DAT_40958af0 = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[0xb] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xd] = 0;
  iVar2 = mali_sys_config_string_get_bool("MALI_NEVERBLIT",0);
  if (iVar2 != 0) {
    DAT_40958af0[9] = 1;
  }
  iVar2 = mali_sys_config_string_get_bool("MALI_FLIP_PIXMAP",0);
  if (iVar2 != 0) {
    DAT_40958af0[10] = 1;
  }
  return;
}



/* 409519bc FUN_409519bc */

/* Boundary evidence: original MIPS .pdata 409519bc..40951b03. Semantic name remains unreviewed. */

int * FUN_409519bc(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = mali_sys_mutex_auto_init(&DAT_40958af4);
  if (iVar1 == 0) {
    mali_sys_mutex_lock(DAT_40958af4);
    if (DAT_40958af0 != (int *)0x0) {
LAB_409519f4:
      mali_sys_mutex_unlock(DAT_40958af4);
      return DAT_40958af0;
    }
    DAT_40958af0 = (int *)mali_sys_calloc(1,0x4c);
    if (DAT_40958af0 != (int *)0x0) {
      FUN_409518f8();
      iVar1 = mali_sys_lock_create();
      DAT_40958af0[5] = iVar1;
      if (iVar1 != 0) {
        iVar1 = mali_sys_mutex_create();
        DAT_40958af0[6] = iVar1;
        if (iVar1 != 0) {
          iVar1 = __mali_named_list_allocate();
          *DAT_40958af0 = iVar1;
          if (iVar1 != 0) {
            iVar1 = __mali_named_list_allocate();
            DAT_40958af0[2] = iVar1;
            if (iVar1 != 0) {
              iVar1 = __mali_named_list_allocate();
              DAT_40958af0[0x12] = iVar1;
              if (iVar1 != 0) {
                puVar2 = (undefined4 *)mali_sys_malloc(0x110);
                DAT_40958af0[0xc] = (int)puVar2;
                if (((puVar2 != (undefined4 *)0x0) && (iVar1 = FUN_40947050(puVar2), iVar1 != 0)) &&
                   (iVar1 = FUN_40947d00((int)DAT_40958af0), iVar1 == 0)) {
                  DAT_40958af0[0xb] = DAT_40958af0[0xb] | 0x20;
                  goto LAB_409519f4;
                }
              }
            }
          }
        }
      }
    }
    FUN_40951638();
    mali_sys_mutex_unlock(DAT_40958af4);
    mali_sys_mutex_destroy(DAT_40958af4);
    DAT_40958af4 = 0;
  }
  return (int *)0x0;
}



/* 40951b04 FUN_40951b04 */

/* Boundary evidence: original MIPS .pdata 40951b04..40951bbb. Semantic name remains unreviewed. */

undefined4 FUN_40951b04(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_409519bc();
  iVar2 = mali_base_context_create();
  piVar1[7] = iVar2;
  if ((iVar2 != 0) && (iVar2 = mali_mem_open(iVar2), iVar2 == 0)) {
    piVar1[0xb] = piVar1[0xb] | 1;
    iVar2 = mali_pp_open(piVar1[7]);
    if (iVar2 == 0) {
      piVar1[0xb] = piVar1[0xb] | 2;
      iVar2 = mali_gp_open(piVar1[7]);
      if (iVar2 == 0) {
        piVar1[0xb] = piVar1[0xb] | 4;
        iVar2 = FUN_40948fa0();
        if (iVar2 == 1) {
          piVar1[0xb] = piVar1[0xb] | 8;
          return 1;
        }
      }
    }
  }
  FUN_409517e4();
  return 0;
}



/* 40951bbc FUN_40951bbc */

/* Boundary evidence: original MIPS .pdata 40951bbc..40951be7. Semantic name remains unreviewed. */

void FUN_40951bbc(void)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  if (piVar1 != (int *)0x0) {
    mali_sys_lock_unlock(piVar1[5]);
  }
  return;
}



/* 40951be8 FUN_40951be8 */

/* Boundary evidence: original MIPS .pdata 40951be8..40951c13. Semantic name remains unreviewed. */

void FUN_40951be8(void)

{
  int *piVar1;
  
  piVar1 = FUN_409519bc();
  if (piVar1 != (int *)0x0) {
    mali_sys_lock_lock(piVar1[5]);
  }
  return;
}



/* 40951c14 FUN_40951c14 */

/* Boundary evidence: original MIPS .pdata 40951c14..40951c73. Semantic name remains unreviewed. */

void FUN_40951c14(int param_1)

{
  int *piVar1;
  
  if (param_1 == 0) {
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_lock(piVar1[5]);
    }
  }
  else if ((param_1 == 1) && (piVar1 = FUN_409519bc(), piVar1 != (int *)0x0)) {
    mali_sys_lock_unlock(piVar1[5]);
  }
  return;
}



/* 40951c74 FUN_40951c74 */

/* Boundary evidence: original MIPS .pdata 40951c74..40951d1f. Semantic name remains unreviewed. */

void FUN_40951c74(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  
  if (((DAT_40958af0 != 0) && ((*(uint *)(DAT_40958af0 + 0x2c) & 0x20) != 0)) &&
     (piVar1 = FUN_409519bc(), piVar1 != (int *)0x0)) {
    piVar1 = FUN_409519bc();
    puVar3 = auStack_10;
    while (iVar2 = __mali_named_list_iterate_begin(*piVar1,puVar3), iVar2 != 0) {
      FUN_4095442c(iVar2,1,param_3,param_4);
      piVar1 = FUN_409519bc();
      puVar3 = auStack_c;
    }
    FUN_40951638();
  }
  if (DAT_40958af4 != 0) {
    mali_sys_mutex_destroy(DAT_40958af4);
    DAT_40958af4 = 0;
  }
  return;
}



/* 40951d20 FUN_40951d20 */

/* Boundary evidence: original MIPS .pdata 40951d20..40951d67. Semantic name remains unreviewed. */

undefined4 FUN_40951d20(HMODULE param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == 0) {
    FUN_40951c74(param_1,0,param_3,param_4);
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 40951de0 FUN_40951de0 */

undefined4 FUN_40951de0(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(param_2 + 0xb8);
  if (iVar2 == iVar3) {
    return 1;
  }
  iVar4 = *(int *)(iVar3 + 0x24);
  if (*(int *)(iVar2 + 0x24) != iVar4) {
    return 0;
  }
  if (*(int *)(iVar2 + 0x14) != *(int *)(iVar3 + 0x14)) {
    return 0;
  }
  if (param_1[2] == 0x30a0) {
    if (*(int *)(iVar2 + 0x34) != *(int *)(iVar3 + 0x34)) {
      return 0;
    }
    if (*(int *)(iVar2 + 0x68) != *(int *)(iVar3 + 0x68)) {
      return 0;
    }
    if ((*(uint *)(iVar3 + 0x5c) & 1) != 0) goto LAB_40951e90;
    uVar1 = *(uint *)(iVar3 + 0x5c) & 4;
  }
  else {
    if (param_1[2] != 0x30a1) goto LAB_40951e90;
    uVar1 = *(uint *)(iVar3 + 0x5c) & 2;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_40951e90:
  if (iVar4 == 0x308e) {
    if (((*(int *)(iVar2 + 4) == *(int *)(iVar3 + 4)) &&
        (*(int *)(iVar2 + 8) == *(int *)(iVar3 + 8))) &&
       (*(int *)(iVar2 + 0xc) == *(int *)(iVar3 + 0xc))) {
      return 1;
    }
  }
  else if ((iVar4 != 0x308f) || (*(int *)(iVar2 + 0x10) == *(int *)(iVar3 + 0x10))) {
    return 1;
  }
  return 0;
}



/* 40951efc FUN_40951efc */

undefined4 FUN_40951efc(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  bVar1 = false;
  if (param_1 != 0) {
    piVar3 = (int *)(param_1 + 4);
    do {
      if (piVar3[-1] == 0x3038) {
        bVar1 = true;
      }
      else {
        if (piVar3[-1] != 0x3098) {
          if (param_3 == 0) {
            return 0;
          }
LAB_40951f84:
          *(undefined4 *)(param_3 + 0x10) = 0x3004;
          return 0;
        }
        if (*(int *)(param_3 + 0xc) != 0x30a0) {
          *(undefined4 *)(param_3 + 0x10) = 0x3004;
          return 0;
        }
        iVar2 = *piVar3;
        if ((iVar2 != 1) && (iVar2 != 2)) goto LAB_40951f84;
        *param_2 = iVar2;
      }
      prefetch(piVar3 + 3,0);
      piVar3 = piVar3 + 2;
    } while (!bVar1);
  }
  return 1;
}



/* 40951f98 FUN_40951f98 */

/* Boundary evidence: original MIPS .pdata 40951f98..40951fff. Semantic name remains unreviewed. */

undefined4 * FUN_40951f98(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x2c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[5] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[6] = param_2;
    puVar1[7] = 0;
    *puVar1 = param_1;
    puVar1[9] = 1;
    puVar1[10] = 0;
  }
  return puVar1;
}



/* 40952008 FUN_40952008 */

/* Boundary evidence: original MIPS .pdata 40952008..409520e7. Semantic name remains unreviewed. */

void FUN_40952008(undefined4 *param_1,int *param_2,int *param_3)

{
  BOOL BVar1;
  int iVar2;
  
  FUN_40955b34();
  if (((param_1[0x28] == 1) &&
      ((iVar2 = *param_3, iVar2 == 0 ||
       ((param_1 != *(undefined4 **)(iVar2 + 8) && (param_1 != *(undefined4 **)(iVar2 + 4))))))) &&
     ((iVar2 = param_3[1], iVar2 == 0 ||
      ((param_1 != *(undefined4 **)(iVar2 + 8) && (param_1 != *(undefined4 **)(iVar2 + 4))))))) {
    param_3[4] = 0x3002;
  }
  else {
    if ((param_2 == (int *)0x0) || (iVar2 = FUN_40951de0(param_2,(int)param_1), iVar2 != 0)) {
      if (((param_1[3] != 0) || (BVar1 = IsWindow((HWND)*param_1), BVar1 != 0)) ||
         (param_3 == (int *)0x0)) goto LAB_409520dc;
      iVar2 = 0x300b;
    }
    else {
      if (param_3 == (int *)0x0) goto LAB_409520dc;
      iVar2 = 0x3009;
    }
    param_3[4] = iVar2;
  }
LAB_409520dc:
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 409520e8 FUN_409520e8 */

/* Boundary evidence: original MIPS .pdata 409520e8..40952153. Semantic name remains unreviewed. */

int FUN_409520e8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 8) == 0x30a0) {
      FUN_40948374(param_1);
    }
    else if (*(int *)(param_1 + 8) == 0x30a1) {
      FUN_409475d8(param_1);
    }
    mali_sys_free(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40952154 FUN_40952154 */

/* Boundary evidence: original MIPS .pdata 40952154..40952237. Semantic name remains unreviewed. */

undefined4 FUN_40952154(int param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2[3] == 0x3038) || (param_1 != param_2[3])) {
    if (param_1 == 0x30a0) {
      param_2[3] = 0x30a0;
      FUN_40947560((int)param_2);
      iVar1 = param_2[1];
      if (iVar1 == 0) {
        return 1;
      }
      if (*(int *)(iVar1 + 0xc) == 0) {
        return 1;
      }
      iVar1 = FUN_40948500(*(int *)(iVar1 + 0xc),*(int *)(iVar1 + 4),*(int *)(iVar1 + 8),
                           (int)param_2);
    }
    else {
      if (param_1 != 0x30a1) {
        iVar1 = 0x300c;
        goto LAB_40952218;
      }
      param_2[3] = 0x30a1;
      FUN_409482f4((int)param_2);
      iVar1 = *param_2;
      if (iVar1 == 0) {
        return 1;
      }
      if (*(int *)(iVar1 + 0xc) == 0) {
        return 1;
      }
      iVar1 = FUN_40947440(*(int *)(iVar1 + 0xc),*(int *)(iVar1 + 4),0,(int)param_2);
    }
    if (iVar1 == 0) {
      iVar1 = 0x3003;
LAB_40952218:
      param_2[4] = iVar1;
      return 0;
    }
  }
  return 1;
}



/* 40952238 FUN_40952238 */

/* Boundary evidence: original MIPS .pdata 40952238..409523df. Semantic name remains unreviewed. */

undefined4 FUN_40952238(uint param_1,uint param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_409522b0:
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x3001;
    }
  }
  else {
    piVar2 = (int *)FUN_4094bc38(param_2,param_1,param_5);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if (param_4 == (int *)0x0) {
      if (param_5 == 0) {
        return 0;
      }
      uVar3 = 0x300c;
    }
    else {
      if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_409522b0;
      if (param_3 == 0x3028) {
        iVar1 = *(int *)(*piVar2 + 0x2c);
LAB_409523b8:
        *param_4 = iVar1;
        return 1;
      }
      if (param_3 == 0x3086) {
        if (piVar2[1] == 0) {
          iVar1 = 0x3038;
        }
        else {
          iVar1 = *(int *)(piVar2[1] + 0xc);
          if (iVar1 == 0) {
            iVar1 = 0x3084;
            goto LAB_409523b8;
          }
          if (iVar1 != 1) {
            if (iVar1 != 2) {
              return 0;
            }
            *param_4 = 0x3085;
            return 1;
          }
          iVar1 = 0x3084;
        }
LAB_40952350:
        *param_4 = iVar1;
        return 1;
      }
      if (param_3 == 0x3097) {
        iVar1 = piVar2[2];
        goto LAB_409523b8;
      }
      if (param_3 == 0x3098) {
        iVar1 = piVar2[6];
        goto LAB_40952350;
      }
      if (param_5 == 0) {
        return 0;
      }
      uVar3 = 0x3004;
    }
    *(undefined4 *)(param_5 + 0x10) = uVar3;
  }
  return 0;
}



/* 409523e0 FUN_409523e0 */

/* Boundary evidence: original MIPS .pdata 409523e0..40952487. Semantic name remains unreviewed. */

uint FUN_409523e0(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1[3] == 0x30a0) {
    if ((int *)param_1[1] == (int *)0x0) {
      return 0;
    }
    uVar1 = FUN_4094bfcc(*(int *)param_1[1],0,1);
    iVar2 = param_1[1];
  }
  else {
    if (param_1[3] != 0x30a1) {
      return 0;
    }
    if ((int *)*param_1 == (int *)0x0) {
      return 0;
    }
    uVar1 = FUN_4094bfcc(*(int *)*param_1,0,1);
    iVar2 = *param_1;
  }
  uVar1 = FUN_4094bfcc(*(int *)(iVar2 + 0xc),uVar1,3);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x40000000;
  }
  return uVar1;
}



/* 40952488 FUN_40952488 */

/* Boundary evidence: original MIPS .pdata 40952488..409525cb. Semantic name remains unreviewed. */

undefined4 FUN_40952488(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  uVar1 = FUN_4094bfcc(*param_3,0,1);
  if (param_1 == 0x3059) {
    piVar2 = (int *)param_2[1];
    if (param_3 == piVar2) {
      piVar2 = (int *)*param_2;
    }
    iVar3 = param_3[1];
    if (piVar2 == (int *)0x0) {
      uVar4 = 0;
    }
    else if ((iVar3 == piVar2[2]) || (uVar4 = 0, iVar3 == piVar2[1])) {
      uVar4 = 1;
    }
    *(undefined4 *)(iVar3 + 0xa0) = uVar4;
    iVar3 = FUN_4094d90c(uVar1,(undefined4 *)param_3[1],0,param_2);
    if ((iVar3 == 1) && (param_3[1] == param_3[2])) {
      param_3[2] = 0;
    }
    param_3[1] = 0;
  }
  else if (param_1 == 0x305a) {
    piVar2 = (int *)param_2[1];
    if (param_3 == piVar2) {
      piVar2 = (int *)*param_2;
    }
    iVar3 = param_3[2];
    if (iVar3 != 0) {
      if ((piVar2 == (int *)0x0) || ((iVar3 != piVar2[2] && (iVar3 != piVar2[1])))) {
        uVar4 = 0;
      }
      *(undefined4 *)(iVar3 + 0xa0) = uVar4;
      FUN_4094d90c(uVar1,(undefined4 *)param_3[2],0,param_2);
      param_3[2] = 0;
    }
  }
  return 1;
}



/* 409525cc FUN_409525cc */

/* Boundary evidence: original MIPS .pdata 409525cc..4095264f. Semantic name remains unreviewed. */

undefined4 FUN_409525cc(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  if (param_3 == 1) {
    *(undefined4 *)(param_2 + 0x24) = 0;
  }
  iVar2 = *(int *)(param_2 + 0x14) + -1;
  *(int *)(param_2 + 0x14) = iVar2;
  if ((*(int *)(param_2 + 0x1c) == 1) && (iVar2 == 0)) {
    *(undefined4 *)(param_2 + 0x14) = 1;
  }
  iVar2 = FUN_409520e8(param_2);
  if (iVar2 == 0) {
    uVar1 = FUN_4094bd58(param_2,param_1,3,param_4,unaff_s1,unaff_s0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40952650 FUN_40952650 */

/* Boundary evidence: original MIPS .pdata 40952650..409526e7. Semantic name remains unreviewed. */

undefined4 FUN_40952650(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0xc) == 0x30a0) {
    FUN_4094827c(param_1);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (*(int *)(param_1 + 0xc) == 0x30a1) {
    FUN_409473b4(param_1);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  uVar1 = FUN_4094bfcc(*param_2,0,1);
  *(undefined4 *)(param_2[3] + 0x1c) = 0;
  *(undefined4 *)(param_2[3] + 4) = 0;
  FUN_409525cc(uVar1,param_2[3],0,param_4);
  param_2[3] = 0;
  return 1;
}



/* 409526e8 FUN_409526e8 */

/* Boundary evidence: original MIPS .pdata 409526e8..409527c7. Semantic name remains unreviewed. */

undefined4 FUN_409526e8(uint param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 != 0) {
    iVar1 = FUN_4094bb8c(param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3008;
    }
    else {
      if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
        iVar2 = FUN_4094bc38(param_2,param_1,param_3);
        if (iVar2 == 0) {
          return 0;
        }
        if ((*(uint *)(iVar1 + 0x20) & 2) == 0) goto LAB_40952794;
      }
      *(undefined4 *)(param_3 + 0x10) = 0x3001;
    }
    return 0;
  }
  iVar2 = FUN_4094b97c(param_2,param_1);
LAB_40952794:
  FUN_409525cc(param_1,iVar2,1,param_4);
  return 1;
}



/* 409527c8 FUN_409527c8 */

/* Boundary evidence: original MIPS .pdata 409527c8..409529a7. Semantic name remains unreviewed. */

void FUN_409527c8(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int in_stack_00000048;
  
  FUN_40955a14();
  iVar6 = 0;
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (in_stack_00000048 != 0) {
      *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3008;
    }
    goto LAB_409529a0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_40952828:
    if (in_stack_00000048 == 0) goto LAB_409529a0;
    uVar5 = 0x3001;
  }
  else {
    iVar2 = FUN_4094badc(param_2,param_1);
    if (iVar2 == 0) {
      if (in_stack_00000048 != 0) {
        *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3005;
      }
      goto LAB_409529a0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_40952828;
    if (param_3 == 0) {
LAB_409528cc:
      param_5 = 1;
      iVar1 = FUN_40951efc(param_4,&param_5,in_stack_00000048);
      if (iVar1 == 1) {
        if (*(int *)(in_stack_00000048 + 0xc) == 0x30a0) {
          piVar3 = FUN_40948668(iVar2,iVar6,param_5,in_stack_00000048);
        }
        else {
          if (*(int *)(in_stack_00000048 + 0xc) != 0x30a1) {
            *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3009;
            goto LAB_409529a0;
          }
          piVar3 = FUN_409476d4(iVar2,iVar6,param_5,in_stack_00000048);
        }
        if (piVar3 != (int *)0x0) {
          *piVar3 = iVar2;
          piVar3[1] = 0;
          piVar3[8] = 0;
          uVar4 = FUN_4094c4ec((int)piVar3,param_1,3);
          if ((uVar4 == 0) || ((uVar4 | 0x40000000) == 0)) {
            FUN_409520e8((int)piVar3);
            *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3003;
          }
          else {
            piVar3[5] = 1;
          }
        }
      }
      goto LAB_409529a0;
    }
    iVar6 = FUN_4094b97c(param_3,param_1);
    if (iVar6 == 0) {
      if (in_stack_00000048 != 0) {
        *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3006;
      }
      goto LAB_409529a0;
    }
    if (*(int *)(in_stack_00000048 + 0xc) == *(int *)(iVar6 + 8)) goto LAB_409528cc;
    uVar5 = 0x3006;
  }
  *(undefined4 *)(in_stack_00000048 + 0x10) = uVar5;
LAB_409529a0:
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x18);
}



/* 409529a8 FUN_409529a8 */

/* Boundary evidence: original MIPS .pdata 409529a8..40952fb7. Semantic name remains unreviewed. */

void FUN_409529a8(uint param_1,uint param_2,int *param_3,uint param_4,undefined4 param_5,int param_6
                 )

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int *in_stack_00000050;
  
  FUN_40955a74();
  param_6 = 0x3038;
  piVar7 = (int *)0x0;
  puVar8 = (undefined4 *)0x0;
  puVar9 = (undefined4 *)0x0;
  piVar6 = (int *)0x0;
  piVar4 = param_3;
  uVar5 = param_4;
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (in_stack_00000050 != (int *)0x0) {
      in_stack_00000050[4] = 0x3008;
    }
    goto LAB_40952acc;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
    if (in_stack_00000050 != (int *)0x0) {
      in_stack_00000050[4] = 0x3001;
    }
    goto LAB_40952acc;
  }
  if (((param_2 != 0) &&
      (piVar4 = in_stack_00000050,
      puVar8 = (undefined4 *)FUN_4094bc88(param_2,param_1,(int)in_stack_00000050),
      puVar8 == (undefined4 *)0x0)) ||
     ((param_3 != (int *)0x0 &&
      (piVar4 = in_stack_00000050,
      puVar9 = (undefined4 *)FUN_4094bc88((uint)param_3,param_1,(int)in_stack_00000050),
      puVar9 == (undefined4 *)0x0)))) goto LAB_40952acc;
  if (param_4 == 0) {
    if ((puVar8 != (undefined4 *)0x0) || (puVar9 != (undefined4 *)0x0)) goto LAB_40952ab8;
LAB_40952ae8:
    if (((*(uint *)(iVar1 + 0x20) & 2) == 0) ||
       (((param_4 == 0 && (param_2 == 0)) && (param_3 == (int *)0x0)))) {
      if (piVar7 != (int *)0x0) {
        if (piVar7[2] == 0x30a0) {
          piVar6 = (int *)in_stack_00000050[1];
          iVar10 = 0x30a0;
LAB_40952b6c:
          if (piVar7[8] != 1) goto LAB_40952b9c;
          if (in_stack_00000050 == (int *)0x0) goto LAB_40952acc;
          iVar1 = 0x300e;
        }
        else {
          if (piVar7[2] != 0x30a1) {
            iVar10 = 0x3038;
            goto LAB_40952b6c;
          }
          piVar6 = (int *)*in_stack_00000050;
          iVar10 = 0x30a1;
          if (puVar8 == puVar9) goto LAB_40952b6c;
          iVar1 = 0x3009;
        }
        in_stack_00000050[4] = iVar1;
        goto LAB_40952acc;
      }
      piVar6 = (int *)FUN_4094c80c(in_stack_00000050,&param_6);
      iVar10 = param_6;
LAB_40952b9c:
      if (((piVar7 != (int *)0x0) && (piVar7[7] == 1)) &&
         ((piVar6 == (int *)0x0 || ((int *)piVar6[3] != piVar7)))) {
        if (in_stack_00000050 == (int *)0x0) goto LAB_40952acc;
        iVar1 = 0x3002;
        goto LAB_40952ac4;
      }
      if (puVar9 == (undefined4 *)0x0) {
        iVar2 = 1;
      }
      else {
        piVar4 = in_stack_00000050;
        iVar2 = FUN_40952008(puVar9,piVar7,in_stack_00000050);
      }
      if (iVar2 != 1) goto LAB_40952acc;
      if (puVar8 == (undefined4 *)0x0) {
        iVar2 = 1;
      }
      else {
        piVar4 = in_stack_00000050;
        iVar2 = FUN_40952008(puVar8,piVar7,in_stack_00000050);
      }
      if (iVar2 != 1) goto LAB_40952acc;
      if (piVar6 != (int *)0x0) {
        if (((piVar7 == (int *)piVar6[3]) && (puVar8 == (undefined4 *)piVar6[1])) &&
           (puVar9 == (undefined4 *)piVar6[2])) goto LAB_40952acc;
        if ((int *)piVar6[3] != (int *)0x0) {
          puVar3 = (undefined4 *)piVar6[1];
          if (((puVar8 != puVar3) && (puVar3[3] == 1)) && (puVar3[0x3f] == 0)) {
            piVar4 = piVar6;
            FUN_40950060((int)puVar3,in_stack_00000050,(int)piVar6);
          }
          if ((((piVar7 != (int *)piVar6[3]) &&
               (iVar2 = FUN_40952650((int)in_stack_00000050,piVar6,piVar4,uVar5), iVar2 != 1)) ||
              ((puVar8 != (undefined4 *)piVar6[1] &&
               (piVar4 = piVar6, iVar2 = FUN_40952488(0x3059,in_stack_00000050,piVar6), iVar2 != 1))
              )) || ((puVar9 != (undefined4 *)piVar6[2] &&
                     (piVar4 = piVar6, iVar2 = FUN_40952488(0x305a,in_stack_00000050,piVar6),
                     iVar2 != 1)))) goto LAB_40952acc;
          if (((*(uint *)(iVar1 + 0x20) & 2) != 0) &&
             (((iVar2 = __mali_named_list_size(*(undefined4 *)(iVar1 + 0x2c)), iVar2 == 0 &&
               (iVar2 = __mali_named_list_size(*(undefined4 *)(iVar1 + 0x28)), iVar2 == 0)) &&
              (iVar2 = __mali_named_list_size(*(undefined4 *)(in_stack_00000050[2] + 0x48)),
              iVar2 == 0)))) {
            FUN_4095442c(iVar1,0,piVar4,uVar5);
          }
        }
      }
      if ((puVar8 == (undefined4 *)0x0) || (piVar7 == (int *)0x0)) goto LAB_40952acc;
      if (piVar6 != (int *)0x0) {
LAB_40952d94:
        if (iVar10 == 0x30a0) {
          in_stack_00000050[1] = (int)piVar6;
        }
        else if (iVar10 == 0x30a1) {
          *in_stack_00000050 = (int)piVar6;
        }
        if (piVar7[2] == 0x30a0) {
          in_stack_00000050[7] = piVar7[3];
          piVar4 = in_stack_00000050;
          iVar10 = FUN_40948500((int)piVar7,(int)puVar8,(int)puVar9,(int)in_stack_00000050);
          if (iVar10 == 0) {
            if (piVar7 == (int *)piVar6[3]) {
              FUN_4094827c((int)in_stack_00000050);
              *(undefined4 *)(piVar6[3] + 0x1c) = 0;
              FUN_409525cc(param_1,(int)piVar7,0,piVar4);
              *(undefined4 *)(piVar6[3] + 4) = 0;
              piVar6[3] = 0;
            }
            if (puVar8 == (undefined4 *)piVar6[1]) {
              FUN_40952488(0x3059,in_stack_00000050,piVar6);
            }
            if (puVar9 == (undefined4 *)piVar6[2]) {
              FUN_40952488(0x305a,in_stack_00000050,piVar6);
            }
            mali_sys_free(in_stack_00000050[1]);
            in_stack_00000050[7] = 0;
            in_stack_00000050[1] = 0;
            goto LAB_40952d7c;
          }
        }
        else if (piVar7[2] == 0x30a1) {
          in_stack_00000050[6] = piVar7[3];
          piVar4 = in_stack_00000050;
          iVar10 = FUN_40947440((int)piVar7,(int)puVar8,1,(int)in_stack_00000050);
          if (iVar10 == 0) {
            if (piVar7 == (int *)piVar6[3]) {
              FUN_409473b4((int)in_stack_00000050);
              *(undefined4 *)(piVar6[3] + 0x1c) = 0;
              FUN_409525cc(param_1,(int)piVar7,0,piVar4);
              *(undefined4 *)(piVar6[3] + 4) = 0;
              piVar6[3] = 0;
            }
            if (puVar8 == (undefined4 *)piVar6[1]) {
              FUN_40952488(0x3059,in_stack_00000050,piVar6);
            }
            if (puVar9 == (undefined4 *)piVar6[2]) {
              FUN_40952488(0x305a,in_stack_00000050,piVar6);
            }
            mali_sys_free(*in_stack_00000050);
            in_stack_00000050[6] = 0;
            *in_stack_00000050 = 0;
            goto LAB_40952d7c;
          }
        }
        *piVar6 = iVar1;
        if (piVar7 != (int *)piVar6[3]) {
          piVar7[5] = piVar7[5] + 1;
        }
        piVar6[3] = (int)piVar7;
        piVar7[7] = 1;
        piVar7[1] = (int)puVar8;
        if (puVar8 != (undefined4 *)piVar6[1]) {
          puVar8[0x27] = puVar8[0x27] + 1;
        }
        piVar6[1] = (int)puVar8;
        puVar8[0x28] = 1;
        if (puVar9 != (undefined4 *)piVar6[2]) {
          puVar9[0x27] = puVar9[0x27] + 1;
        }
        piVar6[2] = (int)puVar9;
        puVar9[0x28] = 1;
        puVar8[0x2b] = 0;
        iVar1 = *(int *)(*(int *)(piVar6[1] + 0xb8) + 0x4c);
        if (iVar1 < 1) {
          iVar1 = *(int *)(*(int *)(piVar6[1] + 0xb8) + 0x48);
          if (iVar1 < 0) {
            puVar8[0x2b] = iVar1;
          }
        }
        else {
          puVar8[0x2b] = iVar1;
        }
        goto LAB_40952acc;
      }
      piVar6 = (int *)mali_sys_malloc(0x10);
      if (piVar6 != (int *)0x0) {
        *piVar6 = 0;
        piVar6[1] = 0;
        piVar6[2] = 0;
        piVar6[3] = 0;
        goto LAB_40952d94;
      }
      if (in_stack_00000050 == (int *)0x0) goto LAB_40952acc;
LAB_40952d7c:
      iVar1 = 0x3003;
    }
    else {
      if (in_stack_00000050 == (int *)0x0) goto LAB_40952acc;
      iVar1 = 0x3001;
    }
  }
  else {
    piVar4 = in_stack_00000050;
    piVar7 = (int *)FUN_4094bc38(param_4,param_1,(int)in_stack_00000050);
    if (piVar7 == (int *)0x0) goto LAB_40952acc;
    if ((puVar8 != (undefined4 *)0x0) && (puVar9 != (undefined4 *)0x0)) goto LAB_40952ae8;
LAB_40952ab8:
    if (in_stack_00000050 == (int *)0x0) goto LAB_40952acc;
    iVar1 = 0x3009;
  }
LAB_40952ac4:
  in_stack_00000050[4] = iVar1;
LAB_40952acc:
                    /* WARNING: Subroutine does not return */
  FUN_40955aac(0x18);
}



/* 40952fb8 FUN_40952fb8 */

/* Boundary evidence: original MIPS .pdata 40952fb8..4095345f. Semantic name remains unreviewed. */

undefined4
FUN_40952fb8(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  
  bVar4 = false;
  if (param_2 != (undefined4 *)0x0) {
    do {
      switch(*param_2) {
      case 0x3020:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        *param_3 = iVar2;
        break;
      case 0x3021:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[5] = iVar2;
        break;
      case 0x3022:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[3] = iVar2;
        break;
      case 0x3023:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[2] = iVar2;
        break;
      case 0x3024:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[1] = iVar2;
        break;
      case 0x3025:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[0xd] = iVar2;
        break;
      case 0x3026:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[0x1a] = iVar2;
        break;
      case 0x3027:
        iVar2 = 0;
        piVar3 = &DAT_40944524;
        do {
          if (param_2[1] == *piVar3) {
            param_3[10] = param_2[1];
            break;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < 4);
        if (iVar2 == 4) goto switchD_40953014_caseD_3030;
        break;
      case 0x3028:
        param_3[0xb] = param_2[1];
        break;
      case 0x3029:
        iVar2 = param_2[1];
        param_3[0xe] = iVar2;
        if (iVar2 == -1) goto switchD_40953014_caseD_3030;
        break;
      case 0x302a:
      case 0x302b:
      case 0x302c:
      case 0x302e:
        break;
      case 0x302d:
        iVar2 = param_2[1];
        if (((iVar2 != -1) && (iVar2 != 1)) && (iVar2 != 0)) goto switchD_40953014_caseD_3030;
        param_3[0x14] = iVar2;
        break;
      case 0x302f:
        param_3[0x16] = param_2[1];
        break;
      default:
        goto switchD_40953014_caseD_3030;
      case 0x3031:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[0x19] = iVar2;
        break;
      case 0x3032:
        iVar2 = 0;
        piVar3 = &DAT_40944540;
        do {
          if (param_2[1] == *piVar3) {
            param_3[0x18] = param_2[1];
            break;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < 2);
        if (iVar2 == 2) goto switchD_40953014_caseD_3030;
        break;
      case 0x3033:
        uVar1 = param_2[1];
        if ((uVar1 != 0xffffffff) && ((uVar1 & 0xfffff998) != 0)) goto switchD_40953014_caseD_3030;
        param_3[0x1b] = uVar1;
        break;
      case 0x3034:
        iVar2 = 0;
        piVar3 = &DAT_40944534;
        do {
          if (param_2[1] == *piVar3) {
            param_3[0x1c] = param_2[1];
            break;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < 3);
        goto joined_r0x409531a8;
      case 0x3035:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[0x1f] = iVar2;
        break;
      case 0x3036:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[0x1e] = iVar2;
        break;
      case 0x3037:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[0x1d] = iVar2;
        break;
      case 0x3038:
        bVar4 = true;
        break;
      case 0x3039:
        iVar2 = param_2[1];
        if (((iVar2 != -1) && (iVar2 != 1)) && (iVar2 != 0)) goto switchD_40953014_caseD_3030;
        param_3[7] = iVar2;
        break;
      case 0x303a:
        iVar2 = param_2[1];
        if (((iVar2 != -1) && (iVar2 != 1)) && (iVar2 != 0)) goto switchD_40953014_caseD_3030;
        param_3[8] = iVar2;
        break;
      case 0x303b:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[0x13] = iVar2;
        break;
      case 0x303c:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[0x12] = iVar2;
        break;
      case 0x303d:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[4] = iVar2;
        break;
      case 0x303e:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40953014_caseD_3030;
        param_3[6] = iVar2;
        break;
      case 0x303f:
        iVar2 = 0;
        piVar3 = &DAT_40944518;
        do {
          if (param_2[1] == *piVar3) {
            param_3[9] = param_2[1];
            break;
          }
          iVar2 = iVar2 + 1;
          prefetch(piVar3 + 2,0);
          piVar3 = piVar3 + 1;
        } while (iVar2 < 3);
joined_r0x409531a8:
        if (iVar2 == 3) {
switchD_40953014_caseD_3030:
          if (param_1 != 0) {
            *(undefined4 *)(param_1 + 0x10) = 0x3004;
          }
          return 0;
        }
        break;
      case 0x3040:
        uVar1 = param_2[1];
        if ((uVar1 != 0xffffffff) && ((uVar1 & 0xfffffff0) != 0)) goto switchD_40953014_caseD_3030;
        param_3[0x17] = uVar1;
        break;
      case 0x3041:
        *param_4 = param_2[1];
        *param_5 = 1;
        break;
      case 0x3042:
        uVar1 = param_2[1];
        if ((uVar1 != 0xffffffff) && ((uVar1 & 0xfffffff0) != 0)) goto switchD_40953014_caseD_3030;
        param_3[0xc] = uVar1;
      }
      param_2 = param_2 + 2;
    } while (!bVar4);
  }
  return 1;
}



/* 40953460 FUN_40953460 */

void FUN_40953460(undefined4 *param_1)

{
  param_1[9] = 0x308e;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0xffffffff;
  param_1[8] = 0xffffffff;
  param_1[10] = 0xffffffff;
  param_1[0xb] = 0xffffffff;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x12] = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0x14] = 0xffffffff;
  param_1[0x16] = 0xffffffff;
  param_1[0x17] = 1;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 4;
  param_1[0x1c] = 0x3038;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0xffffffff;
  param_1[0x1f] = 0xffffffff;
  return;
}



/* 409534e8 FUN_409534e8 */

/* Boundary evidence: original MIPS .pdata 409534e8..4095371b. Semantic name remains unreviewed. */

void FUN_409534e8(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  FUN_40955b34();
  uVar1 = *param_2;
  FUN_4094badc(*param_1,DAT_40958ae8);
  FUN_4094badc(uVar1,DAT_40958ae8);
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 4095371c FUN_4095371c */

/* Boundary evidence: original MIPS .pdata 4095371c..409539b7. Semantic name remains unreviewed. */

undefined4
FUN_4095371c(uint param_1,uint param_2,undefined4 param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_4095378c:
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3001;
    return 0;
  }
  puVar2 = (undefined4 *)FUN_4094badc(param_2,param_1);
  if (puVar2 == (undefined4 *)0x0) {
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3005;
    return 0;
  }
  if (param_4 == (undefined4 *)0x0) {
    if (param_5 == 0) {
      return 0;
    }
    uVar3 = 0x300c;
LAB_4095398c:
    *(undefined4 *)(param_5 + 0x10) = uVar3;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_4095378c;
  switch(param_3) {
  case 0x3020:
    *param_4 = *puVar2;
    return 1;
  case 0x3021:
    uVar3 = puVar2[5];
    goto LAB_40953888;
  case 0x3022:
    uVar3 = puVar2[3];
    break;
  case 0x3023:
    uVar3 = puVar2[2];
    goto LAB_40953888;
  case 0x3024:
    uVar3 = puVar2[1];
    break;
  case 0x3025:
    uVar3 = puVar2[0xd];
    break;
  case 0x3026:
    uVar3 = puVar2[0x1a];
    goto LAB_40953888;
  case 0x3027:
    uVar3 = puVar2[10];
    goto LAB_40953888;
  case 0x3028:
    uVar3 = puVar2[0xb];
    break;
  case 0x3029:
    uVar3 = puVar2[0xe];
    goto LAB_40953888;
  case 0x302a:
    uVar3 = puVar2[0x10];
    goto LAB_40953888;
  case 0x302b:
    uVar3 = puVar2[0x11];
    break;
  case 0x302c:
    uVar3 = puVar2[0xf];
    break;
  case 0x302d:
    uVar3 = puVar2[0x14];
    goto LAB_40953888;
  case 0x302e:
    uVar3 = puVar2[0x15];
    break;
  case 0x302f:
    uVar3 = puVar2[0x16];
    goto LAB_40953888;
  default:
    if (param_5 == 0) {
      return 0;
    }
    uVar3 = 0x3004;
    goto LAB_4095398c;
  case 0x3031:
    uVar3 = puVar2[0x19];
    break;
  case 0x3032:
    uVar3 = puVar2[0x18];
    goto LAB_40953888;
  case 0x3033:
    uVar3 = puVar2[0x1b];
    break;
  case 0x3034:
    uVar3 = puVar2[0x1c];
    goto LAB_40953888;
  case 0x3035:
    uVar3 = puVar2[0x1f];
    break;
  case 0x3036:
    uVar3 = puVar2[0x1e];
    goto LAB_40953888;
  case 0x3037:
    uVar3 = puVar2[0x1d];
    break;
  case 0x3039:
    uVar3 = puVar2[7];
    break;
  case 0x303a:
    uVar3 = puVar2[8];
    goto LAB_40953888;
  case 0x303b:
    uVar3 = puVar2[0x13];
    break;
  case 0x303c:
    uVar3 = puVar2[0x12];
    goto LAB_40953888;
  case 0x303d:
    uVar3 = puVar2[4];
    break;
  case 0x303e:
    uVar3 = puVar2[6];
    goto LAB_40953888;
  case 0x303f:
    uVar3 = puVar2[9];
    break;
  case 0x3040:
    uVar3 = puVar2[0x17];
    break;
  case 0x3042:
    uVar3 = puVar2[0xc];
LAB_40953888:
    *param_4 = uVar3;
    return 1;
  }
  *param_4 = uVar3;
  return 1;
}



/* 409539b8 FUN_409539b8 */

/* Boundary evidence: original MIPS .pdata 409539b8..40953ab3. Semantic name remains unreviewed. */

undefined4 FUN_409539b8(uint param_1,uint *param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 == 0) {
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x3008;
    }
  }
  else {
    if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
      if (param_4 == (int *)0x0) {
        if (param_5 == 0) {
          return 0;
        }
        *(undefined4 *)(param_5 + 0x10) = 0x300c;
        return 0;
      }
      if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
        iVar1 = __mali_named_list_size(*(undefined4 *)(iVar1 + 0x24));
        if (param_2 != (uint *)0x0) {
          if (iVar1 < param_3) {
            param_3 = iVar1;
          }
          iVar1 = FUN_4094bf1c(param_2,param_1,param_3);
        }
        *param_4 = iVar1;
        return 1;
      }
    }
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x3001;
    }
  }
  return 0;
}



/* 40953ab4 FUN_40953ab4 */

/* Boundary evidence: original MIPS .pdata 40953ab4..40953b2b. Semantic name remains unreviewed. */

void FUN_40953ab4(int param_1,HANDLE param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  
  FUN_40955b34();
  param_5 = 0;
  piVar1 = (int *)__mali_named_list_iterate_begin(*(undefined4 *)(param_1 + 0x24),&param_5);
  while ((piVar1 != (int *)0x0 &&
         (((piVar1[0x1b] & 2U) == 0 || (iVar2 = FUN_40949fc8(param_2,piVar1), iVar2 != 1))))) {
    piVar1 = (int *)__mali_named_list_iterate_next(*(undefined4 *)(param_1 + 0x24),&param_5);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x18);
}



/* 40953b2c FUN_40953b2c */

/* Boundary evidence: original MIPS .pdata 40953b2c..40954157. Semantic name remains unreviewed. */

void FUN_40953b2c(uint param_1,undefined4 *param_2,uint *param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,HANDLE param_8,uint *param_9,undefined4 param_10,
                 int param_11,int param_12,int param_13,int param_14,uint param_15,uint *param_16,
                 int param_17,int param_18,int param_19,int param_20,int param_21,int param_22,
                 int param_23,int param_24,int param_25,int param_26,int param_27,int param_28,
                 uint param_29,int param_30,int param_31)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int in_stack_00000088;
  int in_stack_0000008c;
  int in_stack_00000090;
  int in_stack_00000098;
  uint in_stack_0000009c;
  int in_stack_000000a0;
  int in_stack_000000a4;
  int in_stack_000000a8;
  uint in_stack_000000ac;
  int in_stack_000000b0;
  int in_stack_000000b4;
  int in_stack_000000b8;
  int in_stack_000000bc;
  uint *in_stack_00000198;
  int in_stack_0000019c;
  
  FUN_40955a74();
  param_7 = 0;
  uVar8 = 0;
  param_8 = (HANDLE)0x0;
  param_15 = param_4;
  param_16 = param_3;
  iVar2 = FUN_4094bb8c(param_1);
  puVar9 = in_stack_00000198;
  if (iVar2 == 0) {
    if (in_stack_0000019c != 0) {
      *(undefined4 *)(in_stack_0000019c + 0x10) = 0x3008;
    }
    goto LAB_4095414c;
  }
  if ((*(uint *)(iVar2 + 0x20) & 1) != 0) {
    if (in_stack_00000198 == (uint *)0x0) {
      if (in_stack_0000019c == 0) goto LAB_4095414c;
      uVar7 = 0x300c;
LAB_40953bd0:
      *(undefined4 *)(in_stack_0000019c + 0x10) = uVar7;
      goto LAB_4095414c;
    }
    if ((*(uint *)(iVar2 + 0x20) & 2) == 0) {
      FUN_40953460(&param_17);
      iVar3 = FUN_40952fb8(in_stack_0000019c,param_2,&param_17,&param_8,&param_7);
      if (iVar3 != 1) goto LAB_4095414c;
      *puVar9 = 0;
      if (param_28 != -1) {
        if (((0 < (int)param_4) && (uVar8 = FUN_4094be98(param_28,param_1), uVar8 != 0)) &&
           (*puVar9 = 1, param_3 != (uint *)0x0)) {
          *param_3 = uVar8;
        }
        goto LAB_4095414c;
      }
      if ((in_stack_000000ac & 4) == 0) {
        param_12 = -1;
      }
      else {
        param_12 = in_stack_00000098;
      }
      if (in_stack_000000b0 == 0x3038) {
        param_14 = -1;
        param_13 = -1;
        param_11 = -1;
      }
      else {
        param_11 = in_stack_000000bc;
        param_13 = in_stack_000000b8;
        param_14 = in_stack_000000b4;
      }
      uVar10 = in_stack_000000ac;
      if (param_7 == 1) {
        iVar3 = GetObjectW(param_8,0x54,&stack0x00000108);
        if (iVar3 == 0) {
          if (in_stack_0000019c == 0) goto LAB_4095414c;
          uVar7 = 0x300a;
          goto LAB_40953bd0;
        }
        uVar10 = 2;
      }
      piVar4 = (int *)__mali_named_list_iterate_begin(*(undefined4 *)(iVar2 + 0x24),&param_10);
      iVar1 = param_14;
      iVar3 = param_12;
      if (piVar4 != (int *)0x0) {
        param_9 = (uint *)&stack0x000000c8;
        do {
          if ((((((((((param_17 == -1) || (param_17 <= *piVar4)) &&
                    ((param_18 == -1 || (param_18 <= piVar4[1])))) &&
                   ((param_19 == -1 || (param_19 <= piVar4[2])))) &&
                  ((param_20 == -1 || (param_20 <= piVar4[3])))) &&
                 (((((param_21 == -1 || (param_21 <= piVar4[4])) &&
                    ((param_22 == -1 || (param_22 <= piVar4[5])))) &&
                   ((param_23 == -1 || (param_23 <= piVar4[6])))) &&
                  ((param_24 == -1 || (piVar4[7] == param_24)))))) &&
                ((((param_25 == -1 || (piVar4[8] == param_25)) &&
                  ((param_26 == -1 || (piVar4[9] == param_26)))) &&
                 (((param_27 == -1 || (piVar4[10] == param_27)) &&
                  ((param_29 == 0 || ((piVar4[0xc] & param_29) != 0)))))))) &&
               ((((param_30 == -1 || (param_30 <= piVar4[0xd])) &&
                 ((param_31 == -1 || (piVar4[0xe] == param_31)))) &&
                ((in_stack_00000088 == -1 || (piVar4[0x12] == in_stack_00000088)))))) &&
              ((in_stack_0000008c == -1 || (piVar4[0x13] == in_stack_0000008c)))) &&
             (((((in_stack_00000090 == -1 || (piVar4[0x14] == in_stack_00000090)) &&
                ((iVar3 == -1 || (piVar4[0x16] == iVar3)))) &&
               (((in_stack_0000009c == 0xffffffff ||
                 ((piVar4[0x17] & in_stack_0000009c) == in_stack_0000009c)) &&
                (((in_stack_000000a0 == -1 || (in_stack_000000a0 <= piVar4[0x18])) &&
                 ((((in_stack_000000a4 == -1 || (in_stack_000000a4 <= piVar4[0x19])) &&
                   ((in_stack_000000a8 == -1 || (in_stack_000000a8 <= piVar4[0x1a])))) &&
                  ((uVar10 == 0xffffffff || ((piVar4[0x1b] & uVar10) == uVar10)))))))))) &&
              (((in_stack_000000b0 == -1 || (piVar4[0x1c] == in_stack_000000b0)) &&
               ((((((iVar1 == -1 || (piVar4[0x1d] == iVar1)) &&
                   ((param_13 == -1 || (piVar4[0x1e] == param_13)))) &&
                  ((param_11 == -1 || (piVar4[0x1f] == param_11)))) &&
                 ((param_7 != 1 || (iVar5 = FUN_40949fc8(param_8,piVar4), iVar5 != 0)))) &&
                (uVar8 < 0xf)))))))) {
            uVar6 = FUN_4094bfcc((int)piVar4,param_1,4);
            if (uVar6 == 0) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 | 0x60000000;
            }
            uVar8 = uVar8 + 1;
            *param_9 = uVar6;
            param_9 = param_9 + 1;
          }
          piVar4 = (int *)__mali_named_list_iterate_next(*(undefined4 *)(iVar2 + 0x24),&param_10);
          puVar9 = in_stack_00000198;
          param_4 = param_15;
          param_3 = param_16;
        } while (piVar4 != (int *)0x0);
      }
      if (param_3 == (uint *)0x0) {
        *puVar9 = uVar8;
      }
      else if (uVar8 != 0) {
        DAT_40958aec = (uint)(0 < param_18);
        if (0 < param_19) {
          DAT_40958aec = 0 < param_18 | 2;
        }
        if (0 < param_20) {
          DAT_40958aec = DAT_40958aec | 4;
        }
        if (0 < param_22) {
          DAT_40958aec = DAT_40958aec | 8;
        }
        if (0 < param_21) {
          DAT_40958aec = DAT_40958aec | 0x10;
        }
        DAT_40958ae8 = param_1;
        mali_sys_qsort(&stack0x000000c8,uVar8,4,FUN_409534e8);
        uVar10 = param_4;
        if ((int)uVar8 <= (int)param_4) {
          uVar10 = uVar8;
        }
        mali_sys_memcpy(param_3,&stack0x000000c8,uVar10 << 2);
        if ((int)uVar8 <= (int)param_4) {
          param_4 = uVar8;
        }
        *puVar9 = param_4;
      }
      goto LAB_4095414c;
    }
  }
  if (in_stack_0000019c != 0) {
    *(undefined4 *)(in_stack_0000019c + 0x10) = 0x3001;
  }
LAB_4095414c:
                    /* WARNING: Subroutine does not return */
  FUN_40955aac(0x160);
}



/* 40954158 FUN_40954158 */

/* Boundary evidence: original MIPS .pdata 40954158..409541a7. Semantic name remains unreviewed. */

void FUN_40954158(uint param_1)

{
  int iVar1;
  undefined *puVar2;
  
  FUN_40955b34();
  iVar1 = FUN_4094bb8c(param_1);
  if (iVar1 != 0) {
    puVar2 = &DAT_409582cc;
    iVar1 = 0xf;
    do {
      FUN_4094c4ec((int)puVar2,param_1,4);
      iVar1 = iVar1 + -1;
      puVar2 = puVar2 + 0x88;
    } while (iVar1 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 409541a8 FUN_409541a8 */

/* Boundary evidence: original MIPS .pdata 409541a8..409541db. Semantic name remains unreviewed. */

void FUN_409541a8(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_409519bc();
  iVar2 = piVar1[1];
  piVar1[1] = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    FUN_409517e4();
  }
  return;
}



/* 409541dc FUN_409541dc */

/* Boundary evidence: original MIPS .pdata 409541dc..40954237. Semantic name remains unreviewed. */

undefined4 FUN_409541dc(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = FUN_409519bc();
  if ((piVar1[1] == 0) && (iVar2 = FUN_40951b04(), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
    piVar1[1] = piVar1[1] + 1;
  }
  return uVar3;
}



/* 40954238 FUN_40954238 */

/* Boundary evidence: original MIPS .pdata 40954238..4095429f. Semantic name remains unreviewed. */

undefined4 FUN_40954238(undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_1[3] == 0x30a0) {
    piVar2 = (int *)param_1[1];
  }
  else {
    if (param_1[3] != 0x30a1) {
      return 0;
    }
    piVar2 = (int *)*param_1;
  }
  if ((piVar2 != (int *)0x0) && (piVar2[3] != 0)) {
    uVar1 = FUN_4094bfcc(*piVar2,0,1);
    return uVar1;
  }
  return 0;
}



/* 409542a0 FUN_409542a0 */

/* Boundary evidence: original MIPS .pdata 409542a0..4095442b. Semantic name remains unreviewed. */

void FUN_409542a0(uint param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  FUN_40955a14();
  puVar1 = (undefined4 *)FUN_4094bb8c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    if (param_4 != 0) {
      *(undefined4 *)(param_4 + 0x10) = 0x3008;
    }
    goto LAB_40954424;
  }
  if (((puVar1[8] & 1) == 0) && (iVar2 = FUN_409541dc(), iVar2 == 0)) {
    if (param_4 == 0) goto LAB_40954424;
  }
  else {
    iVar2 = FUN_40948f24((HDC)*puVar1);
    if (iVar2 == 0) {
      if ((puVar1[8] & 1) == 0) {
        piVar3 = FUN_409519bc();
        iVar2 = piVar3[1];
        piVar3[1] = iVar2 + -1;
        if (iVar2 + -1 == 0) {
          FUN_409517e4();
        }
      }
      if (param_4 != 0) {
        *(undefined4 *)(param_4 + 0x10) = 0x3008;
      }
      goto LAB_40954424;
    }
    if ((puVar1[8] & 1) != 0) {
LAB_409543f4:
      puVar1[8] = puVar1[8] & 0xfffffffd | 1;
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 1;
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 4;
      }
      goto LAB_40954424;
    }
    FUN_409519bc();
    iVar2 = FUN_40949c34();
    if (iVar2 != 0) {
      iVar2 = FUN_4094b3d0((int)puVar1);
      if (iVar2 != 0) {
        FUN_40949498(*puVar1,puVar1 + 1);
        FUN_40954158(param_1);
        goto LAB_409543f4;
      }
      FUN_409496a8();
    }
    piVar3 = FUN_409519bc();
    iVar2 = piVar3[1];
    piVar3[1] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_409517e4();
    }
  }
  *(undefined4 *)(param_4 + 0x10) = 0x3003;
LAB_40954424:
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x10);
}



/* 4095442c FUN_4095442c */

/* Boundary evidence: original MIPS .pdata 4095442c..409544f3. Semantic name remains unreviewed. */

void FUN_4095442c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = FUN_409519bc();
  iVar2 = FUN_4094bfcc(param_1,0,1);
  iVar3 = param_2;
  FUN_4094c758(piVar1[0x12],iVar2,param_2,param_4);
  FUN_409496a8();
  FUN_4094c12c(param_1,param_2,iVar3,param_4);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (param_2 == 1) {
    mali_sys_free(param_1);
  }
  else {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffc;
    piVar1 = FUN_409519bc();
    iVar3 = piVar1[1];
    piVar1[1] = iVar3 + -1;
    if (iVar3 + -1 == 0) {
      FUN_409517e4();
    }
  }
  return;
}



/* 409544f4 FUN_409544f4 */

/* Boundary evidence: original MIPS .pdata 409544f4..4095460b. Semantic name remains unreviewed. */

undefined4 FUN_409544f4(uint param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint unaff_s4;
  uint unaff_s5;
  
  uVar7 = 1;
  bVar1 = true;
  iVar2 = FUN_4094bb8c(param_1);
  if (iVar2 == 0) {
    if (param_2 != (int *)0x0) {
      param_2[4] = 0x3008;
    }
    uVar7 = 0;
  }
  else {
    uVar6 = *(uint *)(iVar2 + 0x20);
    if (((uVar6 & 1) != 0) && ((uVar6 & 2) == 0)) {
      *(uint *)(iVar2 + 0x20) = uVar6 | 2;
      iVar3 = FUN_4094c3c8(param_1,param_2);
      iVar4 = FUN_4094c2cc(param_1,param_2,param_3,param_4,unaff_s5,unaff_s4);
      if (*(int *)(param_2[2] + 0x48) != 0) {
        iVar5 = __mali_named_list_size();
        bVar1 = false;
        if (iVar5 == 0) {
          bVar1 = true;
        }
      }
      if (((iVar3 == 1) && (iVar4 == 1)) && (bVar1)) {
        FUN_4095442c(iVar2,0,param_3,param_4);
      }
    }
  }
  return uVar7;
}



/* 4095460c FUN_4095460c */

/* Boundary evidence: original MIPS .pdata 4095460c..409546c7. Semantic name remains unreviewed. */

void FUN_4095460c(HDC param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  FUN_40955b34();
  if (param_1 == (HDC)0x0) {
    param_1 = (HDC)0x0;
  }
  iVar1 = FUN_40948f24(param_1);
  if ((iVar1 != 0) && (iVar1 = FUN_4094b760((int)param_1), iVar1 == 0)) {
    puVar2 = (undefined4 *)mali_sys_malloc(0x30);
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = 1;
      *puVar2 = param_1;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      puVar2[3] = 0;
      puVar2[2] = 0;
      puVar2[1] = 0;
      puVar2[6] = 0;
      puVar2[5] = 0;
      puVar2[4] = 0;
      iVar1 = FUN_4094c4ec((int)puVar2,0,1);
      if (iVar1 != 0) goto LAB_409546c0;
      FUN_4095442c((int)puVar2,1,uVar3,param_4);
    }
    if (param_2 != 0) {
      *(undefined4 *)(param_2 + 0x10) = 0x3003;
    }
  }
LAB_409546c0:
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 409546c8 FUN_409546c8 */

/* Boundary evidence: original MIPS .pdata 409546c8..4095480f. Semantic name remains unreviewed. */

void FUN_409546c8(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *in_stack_00000048;
  int in_stack_0000004c;
  
  FUN_40955a14();
  bVar1 = false;
  if (*(int *)(param_2 + 8) != 0x30a1) {
    if (in_stack_0000004c != 0) {
      *(undefined4 *)(in_stack_0000004c + 0x10) = 0x3009;
    }
    goto LAB_40954804;
  }
  uVar6 = 0x30ba;
  bVar2 = FUN_4094ad6c(param_1,param_2,param_4,0x30ba);
  if ((CONCAT31(extraout_var,bVar2) == 1) || (iVar3 = FUN_4094b544(param_4), iVar3 == 1)) {
    if (in_stack_0000004c == 0) goto LAB_40954804;
    uVar6 = 0x3002;
  }
  else {
    if (in_stack_00000048 != (int *)0x0) {
      do {
        if (*in_stack_00000048 == 0x3038) {
          bVar1 = true;
        }
        else if (*in_stack_00000048 != 0x30d2) {
          if (in_stack_0000004c == 0) goto LAB_40954804;
          uVar6 = 0x300c;
          goto LAB_40954740;
        }
        prefetch(in_stack_00000048 + 4,0);
        in_stack_00000048 = in_stack_00000048 + 2;
      } while (!bVar1);
    }
    puVar4 = FUN_4094ac80();
    if (puVar4 != (undefined4 *)0x0) {
      puVar5 = puVar4;
      iVar3 = FUN_40947270(param_2,param_4,puVar4);
      if (iVar3 == 0x3000) {
        puVar4[1] = param_4;
        *puVar4 = param_3;
      }
      else {
        FUN_4094afc8((int)puVar4,1,puVar5,uVar6,in_stack_0000004c,param_6);
        if (in_stack_0000004c != 0) {
          *(int *)(in_stack_0000004c + 0x10) = iVar3;
        }
      }
      goto LAB_40954804;
    }
    if (in_stack_0000004c == 0) goto LAB_40954804;
    uVar6 = 0x3003;
  }
LAB_40954740:
  *(undefined4 *)(in_stack_0000004c + 0x10) = uVar6;
LAB_40954804:
                    /* WARNING: Subroutine does not return */
  FUN_40955a44(0x18);
}



/* 40954810 FUN_40954810 */

/* Boundary evidence: original MIPS .pdata 40954810..40954937. Semantic name remains unreviewed. */

void FUN_40954810(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *in_stack_00000040;
  int in_stack_00000044;
  
  FUN_40955ae4();
  bVar1 = false;
  iVar4 = 0;
  if (*(int *)(param_2 + 8) == 0x30a0) {
    if (in_stack_00000040 != (int *)0x0) {
      do {
        iVar3 = *in_stack_00000040;
        if (iVar3 == 0x3038) {
          bVar1 = true;
        }
        else if (iVar3 == 0x30bc) {
          iVar4 = in_stack_00000040[1];
        }
        else if (iVar3 != 0x30d2) {
          if (in_stack_00000044 != 0) {
            *(undefined4 *)(in_stack_00000044 + 0x10) = 0x300c;
          }
          goto LAB_4095492c;
        }
        prefetch(in_stack_00000040 + 4,0);
        in_stack_00000040 = in_stack_00000040 + 2;
      } while (!bVar1);
    }
    puVar2 = FUN_4094ac80();
    if (puVar2 == (undefined4 *)0x0) {
      if (in_stack_00000044 != 0) {
        *(undefined4 *)(in_stack_00000044 + 0x10) = 0x3003;
      }
    }
    else {
      iVar3 = FUN_40947dfc(param_2,param_3,param_4,iVar4,puVar2);
      if ((iVar3 != 0x3000) &&
         (FUN_4094afc8((int)puVar2,1,param_4,iVar4,puVar2,param_6), in_stack_00000044 != 0)) {
        *(int *)(in_stack_00000044 + 0x10) = iVar3;
      }
    }
  }
  else if (in_stack_00000044 != 0) {
    *(undefined4 *)(in_stack_00000044 + 0x10) = 0x3009;
  }
LAB_4095492c:
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40954938 FUN_40954938 */

/* Boundary evidence: original MIPS .pdata 40954938..40954a83. Semantic name remains unreviewed. */

undefined4 FUN_40954938(int param_1,undefined4 param_2,HANDLE param_3,int *param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined4 *puVar4;
  undefined1 *pv;
  int *piVar5;
  undefined4 uVar6;
  undefined4 in_stack_ffffff80;
  undefined4 in_stack_ffffff84;
  undefined1 auStack_78 [88];
  
  pv = auStack_78;
  bVar1 = false;
  piVar5 = param_4;
  iVar3 = GetObjectW(param_3,0x54,pv);
  if ((iVar3 == 0) ||
     (iVar3 = FUN_40953ab4(param_1,param_3,pv,piVar5,in_stack_ffffff80), iVar3 == 0)) {
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x300c;
    }
  }
  else {
    uVar6 = 0x30b0;
    iVar3 = param_5;
    bVar2 = FUN_4094ad6c(param_1,param_2,(int)param_3,0x30b0);
    if (CONCAT31(extraout_var,bVar2) == 1) {
      if (param_5 == 0) {
        return 0;
      }
      uVar6 = 0x3002;
    }
    else {
      if (param_4 != (int *)0x0) {
        do {
          if (*param_4 == 0x3038) {
            bVar1 = true;
          }
          else if (*param_4 != 0x30d2) {
            if (param_5 == 0) {
              return 0;
            }
            uVar6 = 0x300c;
            goto LAB_40954a58;
          }
          prefetch(param_4 + 4,0);
          param_4 = param_4 + 2;
        } while (!bVar1);
      }
      puVar4 = FUN_4094ac80();
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[8] = 0;
        FUN_4094afc8((int)puVar4,1,param_3,uVar6,iVar3,in_stack_ffffff84);
      }
      if (param_5 == 0) {
        return 0;
      }
      uVar6 = 0x3003;
    }
LAB_40954a58:
    *(undefined4 *)(param_5 + 0x10) = uVar6;
  }
  return 0;
}



/* 40954a84 eglDestroyImageKHR */

/* Boundary evidence: original MIPS .pdata 40954a84..40954ae7. Semantic name remains unreviewed. */

void eglDestroyImageKHR(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x14a84  14  eglDestroyImageKHR */
  FUN_40955b34();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_4094b0c8(param_1,param_2,iVar1,param_4,param_5,param_6);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 40954ae8 eglCreateImageKHR */

/* Boundary evidence: original MIPS .pdata 40954ae8..40954b63. Semantic name remains unreviewed. */

void eglCreateImageKHR(uint param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int *in_stack_00000040;
  
                    /* 0x14ae8  8  eglCreateImageKHR */
  FUN_40955ae4();
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4094b17c(param_1,param_2,param_3,param_4,in_stack_00000040,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40954b64 eglGetProcAddress */

/* Boundary evidence: original MIPS .pdata 40954b64..40954bcf. Semantic name remains unreviewed. */

undefined * eglGetProcAddress(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  
                    /* 0x14b64  23  eglGetProcAddress */
  puVar3 = (undefined *)0x0;
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    puVar3 = FUN_4095097c(param_1,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return puVar3;
}



/* 40954bd0 eglReleaseThread */

/* Boundary evidence: original MIPS .pdata 40954bd0..40954c27. Semantic name remains unreviewed. */

undefined4 eglReleaseThread(void)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x14bd0  31  eglReleaseThread */
  piVar1 = FUN_409519bc();
  if (piVar1 != (int *)0x0) {
    mali_sys_lock_lock(piVar1[5]);
  }
  uVar2 = FUN_4094c8b0();
  piVar1 = FUN_409519bc();
  if (piVar1 != (int *)0x0) {
    mali_sys_lock_unlock(piVar1[5]);
  }
  return uVar2;
}



/* 40954c28 eglGetCurrentSurface */

/* Boundary evidence: original MIPS .pdata 40954c28..40954c93. Semantic name remains unreviewed. */

uint eglGetCurrentSurface(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  
                    /* 0x14c28  20  eglGetCurrentSurface */
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_4094c9b4();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0x3000;
    uVar3 = FUN_4094d840(param_1,puVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 40954c94 eglSurfaceAttrib */

/* Boundary evidence: original MIPS .pdata 40954c94..40954d07. Semantic name remains unreviewed. */

void eglSurfaceAttrib(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x14c94  32  eglSurfaceAttrib */
  FUN_40955ae4();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_4094d1e4(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40954d08 eglQuerySurface */

/* Boundary evidence: original MIPS .pdata 40954d08..40954d7b. Semantic name remains unreviewed. */

void eglQuerySurface(uint param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x14d08  29  eglQuerySurface */
  FUN_40955ae4();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_4094d3e0(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40954d7c eglDestroySurface */

/* Boundary evidence: original MIPS .pdata 40954d7c..40954ddf. Semantic name remains unreviewed. */

void eglDestroySurface(uint param_1,uint param_2)

{
  int *piVar1;
  
                    /* 0x14d7c  15  eglDestroySurface */
  FUN_40955b34();
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4094dd18(param_1,param_2,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 40954de0 eglCreatePixmapSurface */

/* Boundary evidence: original MIPS .pdata 40954de0..40954e53. Semantic name remains unreviewed. */

void eglCreatePixmapSurface(uint param_1,uint param_2,HANDLE param_3,undefined4 param_4)

{
  int *piVar1;
  
                    /* 0x14de0  11  eglCreatePixmapSurface */
  FUN_40955ae4();
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4094ddfc(param_1,param_2,param_3,param_4,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40954e54 eglCreatePbufferFromClientBuffer */

/* Boundary evidence: original MIPS .pdata 40954e54..40954ecf. Semantic name remains unreviewed. */

void eglCreatePbufferFromClientBuffer(uint param_1,int param_2,int param_3,uint param_4)

{
  int *piVar1;
  int *in_stack_00000040;
  
                    /* 0x14e54  9  eglCreatePbufferFromClientBuffer */
  FUN_40955ae4();
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4094dff8(param_1,param_2,param_3,param_4,in_stack_00000040,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40954ed0 eglCreatePbufferSurface */

/* Boundary evidence: original MIPS .pdata 40954ed0..40954f5b. Semantic name remains unreviewed. */

undefined4 eglCreatePbufferSurface(uint param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x14ed0  10  eglCreatePbufferSurface */
  uVar2 = 0;
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_4094e188(param_1,param_2,param_3,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 40954f5c eglCreateWindowSurface */

/* Boundary evidence: original MIPS .pdata 40954f5c..40954fcf. Semantic name remains unreviewed. */

void eglCreateWindowSurface(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
                    /* 0x14f5c  12  eglCreateWindowSurface */
  FUN_40955ae4();
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4094e2e0(param_1,param_2,param_3,param_4,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40954fd0 eglTerminate */

/* Boundary evidence: original MIPS .pdata 40954fd0..4095503b. Semantic name remains unreviewed. */

undefined4 eglTerminate(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x14fd0  35  eglTerminate */
  uVar2 = 0;
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_409544f4(param_1,piVar1,param_3,param_4);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 4095503c eglInitialize */

/* Boundary evidence: original MIPS .pdata 4095503c..409550c7. Semantic name remains unreviewed. */

undefined4 eglInitialize(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x1503c  24  eglInitialize */
  uVar3 = 0;
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    uVar3 = FUN_409542a0(param_1,param_2,param_3,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409550c8 eglGetCurrentDisplay */

/* Boundary evidence: original MIPS .pdata 409550c8..40955123. Semantic name remains unreviewed. */

undefined4 eglGetCurrentDisplay(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x150c8  19  eglGetCurrentDisplay */
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_4094c9b4();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0x3000;
    uVar3 = FUN_40954238(puVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 40955124 eglGetDisplay */

/* Boundary evidence: original MIPS .pdata 40955124..4095518f. Semantic name remains unreviewed. */

undefined4 eglGetDisplay(HDC param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x15124  21  eglGetDisplay */
  uVar3 = 0;
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    uVar3 = FUN_4095460c(param_1,iVar1,param_3,param_4);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 40955190 eglGetCurrentContext */

/* Boundary evidence: original MIPS .pdata 40955190..409551eb. Semantic name remains unreviewed. */

uint eglGetCurrentContext(void)

{
  int *piVar1;
  uint uVar2;
  
                    /* 0x15190  18  eglGetCurrentContext */
  uVar2 = 0;
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_409523e0(piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 409551ec eglMakeCurrent */

/* Boundary evidence: original MIPS .pdata 409551ec..4095525f. Semantic name remains unreviewed. */

void eglMakeCurrent(uint param_1,uint param_2,int *param_3,uint param_4,undefined4 param_5,
                   int param_6)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x151ec  25  eglMakeCurrent */
  FUN_40955ae4();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_409529a8(param_1,param_2,param_3,param_4,iVar1,param_6);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40955260 eglQueryContext */

/* Boundary evidence: original MIPS .pdata 40955260..409552d3. Semantic name remains unreviewed. */

void eglQueryContext(uint param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x15260  27  eglQueryContext */
  FUN_40955ae4();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_40952238(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 409552d4 eglDestroyContext */

/* Boundary evidence: original MIPS .pdata 409552d4..40955337. Semantic name remains unreviewed. */

void eglDestroyContext(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x152d4  13  eglDestroyContext */
  FUN_40955b34();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_409526e8(param_1,param_2,iVar1,param_4);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 40955338 eglCreateContext */

/* Boundary evidence: original MIPS .pdata 40955338..409553ab. Semantic name remains unreviewed. */

void eglCreateContext(uint param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x15338  7  eglCreateContext */
  FUN_40955ae4();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_409527c8(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 409553ac eglQueryAPI */

/* Boundary evidence: original MIPS .pdata 409553ac..409553ff. Semantic name remains unreviewed. */

undefined4 eglQueryAPI(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x153ac  26  eglQueryAPI */
  uVar3 = 0x3038;
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 40955400 eglBindAPI */

/* Boundary evidence: original MIPS .pdata 40955400..4095546b. Semantic name remains unreviewed. */

undefined4 eglBindAPI(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x15400  3  eglBindAPI */
  uVar2 = 0;
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_40952154(param_1,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 4095546c eglReleaseTexImage */

/* Boundary evidence: original MIPS .pdata 4095546c..409554f7. Semantic name remains unreviewed. */

undefined4 eglReleaseTexImage(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x1546c  30  eglReleaseTexImage */
  uVar3 = 0;
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    uVar3 = FUN_40950a78(param_1,param_2,param_3,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409554f8 eglBindTexImage */

/* Boundary evidence: original MIPS .pdata 409554f8..40955583. Semantic name remains unreviewed. */

undefined4 eglBindTexImage(uint param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x154f8  4  eglBindTexImage */
  uVar2 = 0;
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_409514b4(param_1,param_2,param_3,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 40955584 eglSwapInterval */

/* Boundary evidence: original MIPS .pdata 40955584..409555e7. Semantic name remains unreviewed. */

void eglSwapInterval(uint param_1,int param_2)

{
  int *piVar1;
  
                    /* 0x15584  34  eglSwapInterval */
  FUN_40955b34();
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_40950c18(param_1,param_2,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 409555e8 eglCopyBuffers */

/* Boundary evidence: original MIPS .pdata 409555e8..40955673. Semantic name remains unreviewed. */

undefined4 eglCopyBuffers(uint param_1,uint param_2,HANDLE param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  
                    /* 0x155e8  6  eglCopyBuffers */
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_4094c9b4();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0x3000;
    uVar3 = FUN_40950d1c(param_1,param_2,param_3,puVar1,unaff_s3,unaff_s2,unaff_s1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 40955674 eglSwapBuffers */

/* Boundary evidence: original MIPS .pdata 40955674..409556d7. Semantic name remains unreviewed. */

void eglSwapBuffers(uint param_1,uint param_2)

{
  int *piVar1;
  
                    /* 0x15674  33  eglSwapBuffers */
  FUN_40955b34();
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_40950ed8(param_1,param_2,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 409556d8 eglWaitNative */

/* Boundary evidence: original MIPS .pdata 409556d8..40955743. Semantic name remains unreviewed. */

undefined4 eglWaitNative(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x156d8  38  eglWaitNative */
  uVar2 = 0;
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_409510a8(param_1,piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 40955744 eglWaitGL */

/* Boundary evidence: original MIPS .pdata 40955744..4095579f. Semantic name remains unreviewed. */

undefined4 eglWaitGL(void)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x15744  37  eglWaitGL */
  uVar2 = 0;
  piVar1 = (int *)FUN_4094c9b4();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_40951424(piVar1);
    piVar1 = FUN_409519bc();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 409557a0 eglWaitClient */

/* Boundary evidence: original MIPS .pdata 409557a0..409557fb. Semantic name remains unreviewed. */

undefined4 eglWaitClient(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x157a0  36  eglWaitClient */
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_4094c9b4();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0x3000;
    uVar3 = FUN_409511e0(puVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409557fc eglQueryString */

/* Boundary evidence: original MIPS .pdata 409557fc..40955863. Semantic name remains unreviewed. */

void eglQueryString(uint param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x157fc  28  eglQueryString */
  FUN_40955b34();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_40951290(param_1,param_2,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b54(0x10);
}



/* 40955864 eglGetError */

/* Boundary evidence: original MIPS .pdata 40955864..409558af. Semantic name remains unreviewed. */

undefined4 eglGetError(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x15864  22  eglGetError */
  uVar3 = 0x3000;
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0x10);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409558b0 eglGetConfigAttrib */

/* Boundary evidence: original MIPS .pdata 409558b0..40955923. Semantic name remains unreviewed. */

void eglGetConfigAttrib(uint param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x158b0  16  eglGetConfigAttrib */
  FUN_40955ae4();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_4095371c(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40955924 eglChooseConfig */

/* Boundary evidence: original MIPS .pdata 40955924..4095599f. Semantic name remains unreviewed. */

void eglChooseConfig(uint param_1,undefined4 *param_2,uint *param_3,uint param_4,undefined4 param_5,
                    undefined4 param_6,int param_7,HANDLE param_8,uint *param_9,undefined4 param_10,
                    int param_11,int param_12,int param_13,int param_14,uint param_15,uint *param_16
                    ,undefined4 param_17,int param_18,int param_19,int param_20,int param_21,
                    int param_22,int param_23,int param_24,int param_25,int param_26,int param_27,
                    int param_28,uint param_29,int param_30,int param_31)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x15924  5  eglChooseConfig */
  FUN_40955ae4();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_40953b2c(param_1,param_2,param_3,param_4,param_17,iVar1,param_7,param_8,param_9,param_10,
                 param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
                 param_20,param_21,param_22,param_23,param_24,param_25,param_26,param_27,param_28,
                 param_29,param_30,param_31);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 409559a0 eglGetConfigs */

/* Boundary evidence: original MIPS .pdata 409559a0..40955a13. Semantic name remains unreviewed. */

void eglGetConfigs(uint param_1,uint *param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x159a0  17  eglGetConfigs */
  FUN_40955ae4();
  iVar1 = FUN_4094c9b4();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_409539b8(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409519bc();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40955b0c(0x18);
}



/* 40955a14 FUN_40955a14 */

/* Boundary evidence: original MIPS .pdata 40955a14..40955a43. Semantic name remains unreviewed. */

void FUN_40955a14(void)

{
  return;
}



/* 40955a44 FUN_40955a44 */

/* Boundary evidence: original MIPS .pdata 40955a44..40955a73. Semantic name remains unreviewed. */

void FUN_40955a44(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40955a6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x0000001c + param_1))();
  return;
}



/* 40955a74 FUN_40955a74 */

/* Boundary evidence: original MIPS .pdata 40955a74..40955aab. Semantic name remains unreviewed. */

void FUN_40955a74(void)

{
  return;
}



/* 40955aac FUN_40955aac */

/* Boundary evidence: original MIPS .pdata 40955aac..40955ae3. Semantic name remains unreviewed. */

void FUN_40955aac(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40955adc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x00000024 + param_1))();
  return;
}



/* 40955ae4 FUN_40955ae4 */

/* Boundary evidence: original MIPS .pdata 40955ae4..40955b0b. Semantic name remains unreviewed. */

void FUN_40955ae4(void)

{
  return;
}



/* 40955b0c FUN_40955b0c */

/* Boundary evidence: original MIPS .pdata 40955b0c..40955b33. Semantic name remains unreviewed. */

void FUN_40955b0c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40955b2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x00000014 + param_1))();
  return;
}



/* 40955b34 FUN_40955b34 */

/* Boundary evidence: original MIPS .pdata 40955b34..40955b53. Semantic name remains unreviewed. */

void FUN_40955b34(void)

{
  return;
}



/* 40955b54 FUN_40955b54 */

/* Boundary evidence: original MIPS .pdata 40955b54..40955b73. Semantic name remains unreviewed. */

void FUN_40955b54(int param_1)

{
  undefined4 uStackX_c;
  
                    /* WARNING: Could not recover jumptable at 0x40955b6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&uStackX_c + param_1))();
  return;
}



/* 40955b74 FUN_40955b74 */

/* Boundary evidence: original MIPS .pdata 40955b74..40955bc7. Semantic name remains unreviewed. */

void FUN_40955b74(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40945f88(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40955bc8 FUN_40955bc8 */

/* Boundary evidence: original MIPS .pdata 40955bc8..40955bf3. Semantic name remains unreviewed. */

undefined4 FUN_40955bc8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40955b74(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}


